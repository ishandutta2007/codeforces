#include <bits/stdc++.h>

using namespace std;

int n,m;

bool in(int r,int c)
{
    if(r<0||c<0||r>=n||c>=m) return 0;
    else return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	bool rev=0;
	if(n>m)
    {
        swap(n,m);
        rev=1;
    }
    int a[n][m];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) a[o][i]=0;
    int one=1;
    for(int o=0;o<m-1-o+n-1;o++)
    {
        int r=0,c=o;
        while(in(r,c))
        {
            a[r][c]=one;
            one+=2;
            r++;
            c--;
        }
    }
    int two=2;
    for(int o=m-1;m-1-o<o+n-1;o--)
    {
        int r=n-1,c=o;
        while(in(r,c))
        {
            a[r][c]=two;
            two+=2;
            r--;
            c++;
        }
    }
    for(int o=0;o<m;o++)
    {
        if(a[n-1][o]==0)
        {
            int r=n-1,c=o;
            a[r][c]=one++;
            for(int i=n-1;i>0;i--)
            {
                if((n-1-i)&1)
                {
                    r+=i;
                    c-=i;
                }
                else
                {
                    r-=i;
                    c+=i;
                }
                a[r][c]=one++;
            }
        }
    }
    /*for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            cout << a[o][i] << " ";
        }
        cout << endl;
    }*/
    vector<pair<int,int>> res(n*m);
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            res[a[o][i]-1]={o+1,i+1};
        }
    }
    for(int i=0;i<m*n;i++)
    {
        if(rev==0) printf("%d %d\n",res[i].first,res[i].second);
        else printf("%d %d\n",res[i].second,res[i].first);
    }
	return 0;
}