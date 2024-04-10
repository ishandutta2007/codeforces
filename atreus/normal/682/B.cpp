#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

vector <int> v;
stack <int> st;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort (v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
        st.push(v[i]);
    for (int i = 1; i <= n + 1; i++){
        while (!st.empty() && st.top() < i)
            st.pop();
        if (st.empty()){
            cout << i << endl;
            return 0;
        }
        if (!st.empty() && st.top() >= i)
            st.pop();
    }
}