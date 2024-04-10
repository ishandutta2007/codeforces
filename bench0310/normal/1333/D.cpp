#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    char s[n+1];
    scanf("%s",s);
    vector<vector<int>> v;
    int cnt=0;
    while(1)
    {
        vector<int> t;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='R'&&s[i+1]=='L')
            {
                t.push_back(i);
                s[i]='L';
                s[i+1]='R';
                cnt++;
                i++;
            }
        }
        if(t.empty()) break;
        v.push_back(t);
    }
    int m=v.size();
    if(!(m<=k&&k<=cnt)) printf("-1\n");
    else
    {
        for(int i=0;i<m;i++)
        {
            vector<int> &x=v[i];
            int c=min((int)x.size(),k-(m-i-1));
            for(int j=0;j<c-1;j++) printf("1 %d\n",x[j]+1);
            printf("%d ",(int)x.size()-(c-1));
            for(int j=c-1;j<(int)x.size();j++) printf("%d%c",x[j]+1," \n"[j==(int)x.size()-1]);
            k-=c;
        }
    }
    return 0;
}