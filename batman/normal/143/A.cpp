#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e9)

ll r1,r2,d1,d2,c1,c2;

int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
            for(int p=1;p<10;p++)
                for(int q=1;q<10;q++)
                    if(i!=j && j!=p && p!=q && i!=p && i!=q && j!=q && i+j==r1 && p+q==r2 && i+p==c1 && j+q==c2 && i+q==d1 && j+p==d2)
                        return cout<<i<<" "<<j<<"\n"<<p<<" "<<q,0;
    cout<<-1;
    
    return 0;
}