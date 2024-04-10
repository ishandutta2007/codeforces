#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t,n,m,x,y;
    long int oneCount, twoCount;
    char c;
    bool last;

    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        oneCount = 0;
        twoCount = 0;
        cin >> n >> m >> x >> y;
        for(int yi = 0; yi < n; yi ++) {
            cin >> c;
            last = false;
            if(c == '.') {
                last = true;
            }
            for(int xi = 1; xi < m; xi ++) {
                cin >> c;
                if(last) {
                    if(c == '.') {
                        twoCount ++;
                        last = false;
                        continue;
                    }
                    oneCount ++;
                    last = false;
                    continue;
                }
                if(c == '.') {
                    last = true;
                }
            }
            if(last) {
                oneCount ++;
            }
        }
        cout << (oneCount*x+twoCount*min(x*2,y)) << endl;
    }
    return 0;
}