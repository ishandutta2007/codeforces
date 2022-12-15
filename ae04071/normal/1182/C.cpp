#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int cnt[1000001],n;
char str[1000100];

int get(char ch)  {
    switch(ch) {
        case 'a':
            return 0;
        case 'e': return 1;
        case 'i': return 2;
        case 'o': return 3;
        case 'u': return 4;
        default: return -1;
    }
}
vector<string> sa[1000001][5],rem[1000001];
string ans[100000][4];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s",str);
        string tmp = str;
        int m=strlen(str),lst=-1,t=0;
        for(int j=0;j<m;j++) {
            int v=get(str[j]);
            if(v>=0) {
                t++; lst=v;
            }
        }
        sa[t][lst].push_back(tmp);
    }
    int m=0,mx=0;
    for(int i=1;i<=1000000;i++) {
        int cnt=0;
        for(int j=0;j<5;j++) {
            cnt += (int)sa[i][j].size();
        }
        mx += cnt/2;
    }
    mx = min(mx/2, n/4);
    
    for(int i=1;i<=1000000;i++) {
        for(int j=0;j<5;j++) {
            while(mx && (int)sa[i][j].size()>=2) {
                ans[m][1] = sa[i][j].back(); sa[i][j].pop_back();
                ans[m][3] = sa[i][j].back(); sa[i][j].pop_back();
                m++;
                mx--;
            }
            while(!sa[i][j].empty()) {
                rem[i].push_back(sa[i][j].back());
                sa[i][j].pop_back();
            }
        }
    }

    for(int i=1,j=0;i<=1000000;i++) {
        while(j<m && (int)rem[i].size()>=2) {
            ans[j][0] = rem[i].back(); rem[i].pop_back();
            ans[j][2] = rem[i].back(); rem[i].pop_back();
            j++;
        }
    }
    printf("%d\n",m);
    for(int i=0;i<m;i++) {
        printf("%s %s\n%s %s\n",ans[i][0].c_str(),ans[i][1].c_str(),ans[i][2].c_str(),ans[i][3].c_str());
    }

    return 0;
}