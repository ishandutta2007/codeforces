#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1000;
vector<int> path;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n,k,a,b,c,d;
    cin>>n>>k>>a>>b>>c>>d;
    a--; b--; c--; d--;
    if(k<n+1) { cout<<-1; return 0; }

    int e=2,last=-1;

    for(int i=0; i<n; )
        if(i==a||i==b||i==c||i==d) i++;
        else
        {
            last=i;
            path.pb(i);
            bool dif=false;
            for(int j=i+1; j<n; j++)
                if(j!=a&&j!=b&&j!=c&&j!=d)
                {
                    i=j;
                    e++;
                    dif=true;
                    break;
                }
            if(!dif) break;
        }

    if(n>4)
        e+=2;

    if(last!=-1)
        e+=2;

    if(e<n+1) { cout<<-1; return 0; }

    cout<<a+1<<' '<<c+1<<' ';
    for(int i=0; i<n-4; i++)
        cout<<path[i]+1<<' ';
    cout<<d+1<<' '<<b+1<<endl;
    cout<<c+1<<' '<<a+1<<' ';
    for(int i=0; i<n-4; i++)
        cout<<path[i]+1<<' ';
    cout<<b+1<<' '<<d+1;
    return 0;
}