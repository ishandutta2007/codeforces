#include <fstream>
#include <vector>

#define M 5200


using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

long n;
vector<long> a[M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (long i=0,x; i<2*n; ++i){
        cin>>x;
        a[x].push_back(i+1);
    }

    for (long i=0; i<M;++i)
    if (a[i].size()%2){
        cout<<"-1\n";
        return 0;
    }

    for (long i=0; i<M;++i)
    for (long j=0; j<a[i].size(); j+=2)
    cout<<a[i][j]<<" "<<a[i][j+1]<<"\n";

    return 0;
}