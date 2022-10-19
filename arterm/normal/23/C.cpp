#include <iostream>
#include <algorithm>


#define f first
#define s second
#define mp make_pair
#define a f.f
#define b f.s

#define M 200100


using namespace std;


long n;
pair<pair<long,long>,long> p[M];

void ans(void){
    cin>>n;
    n--;
    for (long x,y,i=0; i<=2*n; ++i){
        cin>>x>>y;
        p[i]=mp(mp(-x,y),i+1);
    }

    sort(p,p+(2*n+1));


    cout<<"YES\n";
    cout<<p[0].s<<" ";
    for (long i=1; i<=2*n; i+=2)
    cout<<(p[i].b<p[i+1].b ? p[i+1].s:p[i].s),cout<<" ";

    cout<<"\n";


}

int main()
{
    ios_base::sync_with_stdio(0);
    long t;
    cin>>t;
    while (t--)
    ans();

    return 0;
}