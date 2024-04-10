#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n;
string a[3000],b[3000];
int l[3000],r[3000],pi[3000],f[3000];
char str[3010];

void getpi(string &s){
    int j=0;
    for(int i=1;i<sz(s);i++){
        while(j && s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])pi[i]=++j;
    }
}
int kmp(string &a,string &b){
    int j=0;
    for(int i=0;i<sz(a);i++){
        while(j&&a[i]!=b[j])j=pi[j-1];
        if(a[i]==b[j]){
            ++j;
            if(sz(b)==j)return i-j+1;
        }
    }
    return -1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",str),a[i]=str;
    for(int i=0;i<n;i++)scanf("%s",str),b[i]=str;

    string ta,tb;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i])f[i]=1;
        else{
            cnt++;
            int l=0,r=sz(a[i])-1;
            for(;a[i][l]==b[i][l];l++);
            for(;a[i][r]==b[i][r];r--);
            ::l[i]=l; ::r[i]=r;

            if(sz(ta)==0){
                ta=a[i].substr(l,r-l+1);
                tb=b[i].substr(l,r-l+1);
            }else{
                if(ta!=a[i].substr(l,r-l+1)||tb!=b[i].substr(l,r-l+1)){
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    while(true){
        int chk=1;
        char ch=-1;
        for(int i=0;i<n;i++)if(!f[i]){
            if(l[i]==0 || (ch!=-1&&ch!=a[i][l[i]-1])){
                chk=0;
                break;
            }
            ch=a[i][l[i]-1];
        }
        if(!chk) break;
        for(int i=0;i<n;i++)if(!f[i])l[i]--;
    }
    while(true){
        int chk=1;
        char ch=-1;
        for(int i=0;i<n;i++)if(!f[i]){
            if(r[i]==sz(a[i])-1 || (ch!=-1&&ch!=a[i][r[i]+1])){
                chk=0;
                break;
            }
            ch=a[i][r[i]+1];
        }
        if(!chk)break;
        for(int i=0;i<n;i++)if(!f[i])r[i]++;
    }

    if(!cnt){
        puts("YES");
        for(int i=0;i<4000;i++)printf("a");
        puts("");
        for(int i=0;i<4000;i++)printf("a");
        puts("");
    }else{
        string sa,sb;
        for(int i=0;i<n;i++)if(!f[i]){
            sa=a[i].substr(l[i],r[i]-l[i]+1);
            sb=b[i].substr(l[i],r[i]-l[i]+1);
            break;
        }

        getpi(sa);
        for(int i=0;i<n;i++){
            int v=kmp(a[i],sa);\
            if(f[i]&&v!=-1 || !f[i]&&v!=l[i]){
                puts("NO");
                return 0;
            }
        }
        puts("YES");
        printf("%s\n%s\n",sa.c_str(),sb.c_str());
    }

    return 0;
}