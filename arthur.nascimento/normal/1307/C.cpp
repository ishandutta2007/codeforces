#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug printf
using namespace std;

char str[maxn];
ll fr[maxn];

int foi[30];
ll ans[30][30];
 
int main() {
    
    scanf(" %s",str);
    
    int n = strlen(str);
    
    for(int i=0;i<n;i++)
        fr[str[i]-'a']++;
        
   for(int i=n-1;i>=0;i--){
       
       for(int j=0;j<26;j++)
        ans[str[i]-'a'][j] += foi[j];
        foi[str[i]-'a']++;
       
   }
   ll res = 0;
   for(int i=0;i<26;i++) res = max(res,fr[i]);
   for(int i=0;i<26;i++) for(int j=0;j<26;j++) res = max(res, ans[i][j]);
   printf("%lld\n",res);
    
}