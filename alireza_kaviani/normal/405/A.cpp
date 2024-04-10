#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define     Time            printf("\nTime : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC);
#define     fori(i,j,k)     for(int (i)=(j);(i)<(k);(i)++)
#define     rep(i,k)        fori(i,0,k)
#define     all(x)          (x).begin(),(x).end()
#define     testin          freopen("a.in.txt","r+",stdin)
#define     testout         freopen("a.out.txt","w+",stdout)
#define     pb              push_back()
#define     ppb             pop_back()

int main()
{
    int n;
    cin >> n;

    vector <int> vec(n);

    rep(i,n)
    {
        cin >> vec[i];
    }

    sort(all(vec));

    for(auto i:vec)
    {
        cout << i << " ";
    }
}