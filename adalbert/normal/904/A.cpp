#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

signed main()
{
    int v1,v2,v3,vm;
    cin>>v1>>v2>>v3>>vm;
    for (int i=0;i<=200;i++)
        for (int j=0;j<i;j++)
            for (int l=0;l<j;l++)
            if (v1<=i && v2<=j && v3<=l && 2*v1>=i
                && 2*v2>=j && 2*v3>=l &&
                vm<=i && vm<=j && vm<=l &&
                2*vm<i && 2*vm<j && 2*vm>=l)
                {
                    cout<<i<<'\n';
                    cout<<j<<'\n';
                    cout<<l<<'\n';
                    return(0);
                }
    cout<<-1;
}