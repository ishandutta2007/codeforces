#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int aa,bb,cc;
        int mini = 1e9;
        for (int i = 1; i <=2*a ; i++) 
        {
            for(int j = i; j<=5e4; j+=i)
            {
                for(int k = j; k<= 5e4; k+=j)
                {
                    if(abs(a-i)+abs(b-j)+abs(c-k)<mini)
                    {
                        mini = abs(a-i)+abs(b-j)+abs(c-k);
                        aa = i, bb= j, cc= k;
                    }
                }
            }
        }
        cout<<mini<<endl;
        cout<<aa<<" "<<bb<<" "<<cc<<endl;
    }
    return 0;
}