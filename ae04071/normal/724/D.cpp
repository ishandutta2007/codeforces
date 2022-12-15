#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

char s[100100];
int n,m,arr[100100];

bool check(int v) {
    int lst=-1;
    for(int i=0;i<n;i++) if(s[i]<=v+'a') {
        if(i-lst > m) return false;
        lst = i;
    }
    if(n-lst>m) return false;
    return true;
}
string trace(int v) {
    int lst=-1,cur=-1;
    string ret;
    for(int i=0;i<n;i++) {
        if(i-lst > m) {
            ret.push_back(v+'a');
            lst = cur;
        }
        if(s[i]==v+'a') cur=i;
        else if(s[i]<v+'a') {
            ret.push_back(s[i]);
            lst=i;
        }
    }
    if(n-lst > m) {
        ret.push_back(v+'a');
    }
    sort(ret.begin(),ret.end());
    return ret;
}

int main() {
    scanf("%d%s",&m,s);
    n=strlen(s);

    for(int i=0;i<26;i++) if(check(i)) {
        string ans = trace(i);
        printf("%s\n",ans.c_str());
        break;
    }

    return 0;
}