//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 100002
#define MOD 1000000007

	LLI T,n,in,i,m,j,cnt,l;
	string s;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c;
    cin>>r>>c;
    char s[r][c+1];

    for(int i=0;i<r;++i)
    {
        cin>>s[i];
    }

    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            if(s[i][j]=='S')
            {
                if(i>0)
                {
                    if(s[i-1][j]=='W')
                    {
                        cout<<"No";
                        return 0;
                    }
                    if(s[i-1][j]=='.')
                    {
                        s[i-1][j]='D';
                    }
                }

                if(j>0)
                {
                    if(s[i][j-1]=='W')
                    {
                        cout<<"No";
                        return 0;
                    }
                    if(s[i][j-1]=='.')
                    {
                        s[i][j-1]='D';
                    }
                }

                if(i<r-1)
                {
                    if(s[i+1][j]=='W')
                    {
                        cout<<"No";
                        return 0;
                    }
                    if(s[i+1][j]=='.')
                    {
                        s[i+1][j]='D';
                    }
                }

                if(j<c-1)
                {
                    if(s[i][j+1]=='W')
                    {
                        cout<<"No";
                        return 0;
                    }
                    if(s[i][j+1]=='.')
                    {
                        s[i][j+1]='D';
                    }
                }
            }
        }
    }

    cout<<"Yes\n";
    for(int i=0;i<r;++i)
    {
        cout<<s[i]<<"\n";
    }


	return 0;
}