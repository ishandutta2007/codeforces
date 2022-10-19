

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>


using namespace std;

int main(){
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long l = 2000000005;
        long long cl = 2000000005;
        int r = -1;
        long long cr = 2000000005;
        long long crl = 2000000005;
        for (int i = 0; i < n; i++) {
       
            long long a, b, c;
            cin >> a >> b >> c;
            if (a <= l && b >= r) {
                if (a == l && b == r) crl = min(crl, c);
                else crl = c;
                if (a < l) {
                    l = a;
                    cl = c;
                }
                else if (a == l) {
                    cl = min(cl, c);
                }
                if (b > r) {
                    r = b;
                    cr = c;
                }
                else if (b == r) {
                    cr = min(cr, c);
                }

            }
            else {
                if (a < l) {
                    l = a;
                    cl = c;
                    crl = 2000000005;
                }
                else if (a == l) {
                    cl = min(cl, c);
                }
                if (b > r) {
                    r = b;
                    cr = c;
                    crl = 2000000005;
                }
                else if (b == r) {
                    cr = min(cr, c);
                }
            }
            cout << min(cr + cl, crl) << endl;
        }
    }


}