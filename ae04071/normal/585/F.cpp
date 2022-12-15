#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n,v,sni;
char s[1010],sa[100],sb[100];

struct Node{
    Node *nxt[10],*fl;
    Node *onxt[10];
    int lst,ni,len;
    Node() {
        ni = sni++;
        for(int i=0;i<10;i++) nxt[i] = nullptr;
        for(int i=0;i<10;i++) onxt[i] = nullptr;
        fl = nullptr;
        lst = len = 0;
    }
}*root = new Node();

void add(Node *cur,char *str, int len) {
    cur->len = len;
    if(len == v) cur->lst=1;
    else {
        Node *nxt;
        if(cur->nxt[*str] == nullptr) cur->nxt[*str] = new Node();
        nxt = cur->nxt[*str];
        add(nxt,str+1,len+1);
    }
}
void make_aho() {
    queue<Node*> que;
    root->fl = root;
    for(int i=0;i<10;i++) {
        if(root->nxt[i] != nullptr) {
            root->nxt[i]->fl = root;
            que.push(root->nxt[i]);
        }
    }
    while(!que.empty()) {
        Node *cur=que.front();que.pop();
        for(int i=0;i<10;i++) if(cur->nxt[i] != nullptr) {
            Node *tmp = cur->fl;
            while(tmp->nxt[i]==nullptr && tmp!=root) tmp = tmp->fl;
            if(tmp->nxt[i] != nullptr) cur->nxt[i]->fl = tmp->nxt[i];
            else cur->nxt[i]->fl = tmp;
            que.push(cur->nxt[i]);
        }
    }
}

void preproc() {
    queue<Node*> que;
    que.push(root);
    while(!que.empty()) {
        Node *cur=que.front();que.pop();
        for(int i=0;i<10;i++) {
            if(cur->nxt[i] != nullptr) cur->onxt[i] = cur->nxt[i], que.push(cur->nxt[i]);
            else {
                Node *fl = cur->fl;
                while(fl->nxt[i]==nullptr && fl!=root) fl = fl->fl;
                if(fl->nxt[i]!=nullptr) cur->onxt[i] = fl->nxt[i];
                else cur->onxt[i] = fl;
            }
        }
    }
}

int dp[25010][51][2][2],m,cnt[51][2][2];
int sv[51];

int get(int idx,int f,int lf) {
    int &ret=cnt[idx][f][lf];
    if(ret!=-1) return ret;

    ret=0;
    if(idx==m) return ret=1;

    for(int i=lf;i <= (f ? 9 : sv[idx]); i++) ret = (ret+get(idx+1,f|(i<sv[idx]),0))%MOD;
    return ret;
}
int DP(Node *cur,int idx,int f,int lf) {
    int &ret=dp[cur->ni][idx][f][lf];
    if(ret!=-1) return ret;

    ret=0;
    if(cur->lst) return ret = get(idx,f,lf);
    if(idx==m) return ret;

    for(int i=lf;i<= (f ? 9 : sv[idx]);i++) {
        ret = (ret + DP(cur->onxt[i], idx+1, f | (i<sv[idx]), 0))%MOD;
    }
    return ret;
}
int proc(char *str,bool f) {
    m=strlen(str);
    for(int i=0;i<m;i++) sv[i] = str[i]-'0';
    if(f) {
        sv[m-1]-=1;
        
        int i=m-1;
        for(;i>0 && sv[i]<0;i--) {
            sv[i]+=10; sv[i-1]-=1;
        }
        if(i==0 && sv[i]==0)  return 0;
    }
    memset(cnt,-1,sizeof(cnt));
    get(0,0,1);
    memset(dp,-1,sizeof(dp));
    return DP(root,0,0,1);
}

int main() {
    scanf("%s%s%s",s,sa,sb);
    n = strlen(s);

    for(int i=0;i<n;i++) s[i] -= '0';

    v = strlen(sa) / 2;
    for(int i=0;i<=n-v;i++) add(root,&s[i],0);

    make_aho();
    preproc();

    printf("%d\n",((proc(sb, false) - proc(sa, true))%MOD+MOD)%MOD);

    return 0;
}