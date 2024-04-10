 
#include <iostream>
using namespace std;
 
bool d[50][50];
 
int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        d[x-1][y-1] = true;
        d[y-1][x-1] = true;
    }
 
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                d[i][j] |= d[i][k] & d[k][j];
 
    int res = 0;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++)
            if(d[i][j]){
                if(i > j) break;
                cnt++;
            }
        res += max(0,cnt - 1);
    }
 
    cout << (1LL<<res) << endl;
 
    return 0;
}