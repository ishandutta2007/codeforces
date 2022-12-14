#include <iostream>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

stack <int> mystack;
const int maxn = 1e5 + 500;
int a[maxn];

int main(){
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        while (!mystack.empty() && mystack.top() < a[i]){
            ans = max(ans, (mystack.top() ^ a[i]));
            mystack.pop();
        }
        if (!mystack.empty())
            ans = max(ans, (mystack.top() ^ a[i]));
        mystack.push(a[i]);
    }
    cout << ans << endl;
    return 0;
}