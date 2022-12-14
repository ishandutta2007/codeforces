#include <iostream>
#include <stack>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn], murder[maxn], t[maxn];
stack <pair <int, int> > st;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    st.push(make_pair(0, 0));
    t[0] = 10000000;
    for (int i = 1; i < n; i++){
        while (!st.empty() && a[i] > a[st.top().second]){
            st.pop();
        }
        while (!st.empty() && murder[st.top().second] >= t[st.top().second]){
            st.pop();
        }
        if (st.empty())
            t[i] = 10000000;
        else{
            murder[st.top().second] ++;
            t[i] = murder[st.top().second];
        }
        st.push(make_pair(t[i], i));
    }
    int k = 0;
    for (int i = 0; i < n; i++){
        k = max(k, murder[i]);
    }
    cout <<  k << endl;
    return 0;
}