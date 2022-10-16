#include <iostream>
#include <set>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], b[MAXN], inva[MAXN], invb[MAXN], addl, addr;
set< pair<int, int> > stl, str;

int getAns() {
    if(stl.empty())
        return str.begin()->first + addr;
    if(str.empty())
        return stl.begin()->first + addl;
    return min(stl.begin()->first + addl, str.begin()->first + addr);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        inva[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        invb[b[i]] = i;
    }
    for(int i = 0; i < n; i++)
        if(inva[i] < invb[i])
            stl.insert(make_pair(invb[i] - inva[i], i));
        else
            str.insert(make_pair(inva[i] - invb[i], i));
    for(int i = 0; i < n; i++) {
        cout << getAns() << '\n';
        addr++;
        addl--;
        while(!stl.empty() && !(stl.begin()->first + addl)) {
            str.insert(make_pair(-addr, stl.begin()->second));
            stl.erase(stl.begin());
        }
        str.erase(make_pair(inva[b[i]] - addr + 1, b[i]));
        if(inva[b[i]] == n - 1)
            str.insert(make_pair(-addr, b[i]));
        else
            stl.insert(make_pair(n - 1 - inva[b[i]] - addl, b[i]));
    }
    return 0;
}