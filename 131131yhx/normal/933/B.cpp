#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

ll p, k;

vector <int> Ans;

int main() {
    scanf("%lld%lld", &p, &k);
    for(int t = 1; p; t = -t)
        if(p % k == 0) {
            Ans.push_back(0);
            p /= k;
        } else if(t == 1) {
            Ans.push_back(p % k);
            p = p / k;
        } else {
            Ans.push_back(k - p % k);
            p = p / k + 1;
        }
    printf("%d\n", Ans.size());
    for(int i = 0; i < Ans.size(); i++) printf("%d ", Ans[i]);
    return 0;
}