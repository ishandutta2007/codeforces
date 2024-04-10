#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

struct node{
    node *nxt[26],*fl,*cl;
    int idx;
    node () {
        idx=-1;
        for(int i=0;i<26;i++) nxt[i] = nullptr;
        fl=cl=nullptr;
    }
}*root;

int n,m;
lli cnt[210001];

char s[210001],t[210001];
void add(node *cur,char *ch,int i) {
    if(!(*ch)) {
        if(cur->idx!=-1) cnt[i] = cnt[cur->idx];
        cur->idx = i;
        cnt[i]++;
    }
    else {
        int nx=*ch - 'a';
        if(!cur->nxt[nx]) cur->nxt[nx] = new node();
        add(cur->nxt[nx], ch+1, i);
    }
}
void make_aho() {
    queue<node*> que;
    root->fl = root;
    for(int i=0;i<26;i++) if(root->nxt[i]) {
        root->nxt[i]->fl = root;
        que.push(root->nxt[i]);
    }
    while(!que.empty()) {
        node *cur=que.front();que.pop();
        for(int i=0;i<26;i++) if(cur->nxt[i]) {
            node *fl = cur->fl;
            while(fl!=root && !fl->nxt[i]) fl = fl->fl;
            if(fl->nxt[i]) cur->nxt[i]->fl = fl->nxt[i], fl = fl->nxt[i];
            else cur->nxt[i]->fl = fl;

            if(cur->nxt[i]->fl->idx!=-1) cur->nxt[i]->cl = fl;
            else cur->nxt[i]->cl = cur->nxt[i]->fl->cl;
            
            que.push(cur->nxt[i]);
        }
    }
}

lli ans=0,fs[200100],ss[200100];
void solve() {
    node *cur = root;
    for(int i=0;i<n;i++) {
        int nx = s[i]-'a';
        while(cur!=root && !cur->nxt[nx]) cur=cur->fl;
        if(cur->nxt[nx]) cur=cur->nxt[nx];

        if(cur->idx!=-1) {
            fs[i] += cnt[cur->idx];
            
            int v=i-ss[cur->idx];
            if(v>=0) ans += cnt[cur->idx]*fs[v];
        }
        node *t = cur->cl;

        while(t) {
            fs[i] += cnt[t->idx];
            
            int v=i-ss[t->idx];
            if(v>=0) ans += cnt[t->idx]*fs[v];
            t = t->cl;
        }
    }
}

lli bs[200100];

int main() {
    scanf("%s",s);
    n = strlen(s);
    scanf("%d",&m);

    root = new node();
    for(int i=0;i<m;i++) {
        scanf("%s",t);
        add(root, t, i);
        
        int sz=strlen(t);
        ss[i] = sz;
    }
    make_aho();
    solve();

    printf("%lld\n",ans);
    
    return 0;
}