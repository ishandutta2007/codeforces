#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

int n;
char tmp[100100];
string str[100100];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s",tmp);
        str[i] = tmp;
    }
    
    int f=1;
    for(auto &ch:str[n-1]) {
        if(ch != str[n-1][0]) {
            f=0;
            break;
        }
    }

    int res=0;
    if(!f) {
        int con_max=0,con_first=0,con_last=0;
        for(int i=0,j=0;i<sz(str[n-1]);i=j) {
            for(j=i;j<sz(str[n-1]) && str[n-1][i] == str[n-1][j];j++);
            con_max = max(con_max, j-i);
            if(i==0) con_first = j-i;
            if(j==sz(str[n-1])) con_last = j-i;
        }
        if(str[n-1][0] == str[n-1].back()) {
            for(int i=0;i<n-1;i++) for(auto &ch:str[i]) {
                if(ch == str[n-1][0]) con_max = max(con_max, con_first+con_last+1);
            }
        } else {
            for(int i=0;i<n-1;i++) for(auto &ch:str[i]) {
                if(ch == str[n-1][0]) con_max = max(con_max, con_first+1);
                if(ch == str[n-1].back()) con_max = max(con_max, con_last+1);
            }
        }
        res = max(res,con_max);
    } else {
        int i=n-2, j=sz(str[n-2])-1,f=1;

        for(;i>=0 && f;i--) {
            for(j=sz(str[i])-1;j>=0;j--) {
                if(str[i][j] != str[n-1][0]) {
                    f=0;
                    break;
                }
            }
            if(!f) break;
        }
        if(i==-1) {
            int ans=0;
            for(int i=0;i<n;i++) {
                ans += (ans+1)*sz(str[i]);
            }
            res = max(res, ans);
        } else {
            int ans=0;
            for(int j=0,k=0;j<sz(str[i]);j=k) {
                if(str[i][j] != str[n-1][0]) {
                    k++;
                    continue;
                }
                for(k=j;k<sz(str[i]) && str[i][j]==str[i][k]; k++);
                ans=max(ans,k-j);
            }
            {
                int ans=0;
                for(int j=i+1;j<n;j++) ans += (ans+1)*sz(str[j]);
                for(int j=0;j<i;j++) for(auto &ch:str[j]) if(ch==str[n-1].back()) res=max(res, ans*2+1);
            }
            i++;
            for(;i<n;i++)  {
                ans += (ans+1)*sz(str[i]);
            }
            res = max(res, ans);
        }
        for(int i=0;i<n-1;i++) for(int j=0;j<sz(str[i]);j++) if(str[i][j]==str[n-1][0]){
            res=max(res, 2*sz(str[n-1])+1);
        }
    }

    printf("%d\n",max(res,1));
    
    return 0;
}