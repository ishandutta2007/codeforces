#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '

vector<int> vec , sec;
int main()
{
    int n;
    cin >> n;

    vec.resize(n);
    sec.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> vec[i];
        sec[i]=vec[i];
    }

    Sort(sec);
    int i,j;
    for(i=0;i<n;i++)
    {
        if(vec[i]!=sec[i])
        {
            break;
        }
    }
    for(j=n-1;j>=0;j--)
    {
        if(vec[j]!=sec[j])
        {
            break;
        }
    }
    if(i==n)i=n-1;
    if(j==-1)j=0;

    if(i==n-1 && j==0)
    {
        cout << "yes\n" << "1 1";
        return 0;
    }

    reverse(vec.begin()+i,vec.begin()+j+1);
    for(int k=0;k<n;k++)
    {
        if(vec[k]!=sec[k])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes\n" << i+1 << ends << j+1;


    return 0;
}