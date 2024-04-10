#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 0;
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > m) m = x;
        else {
            ans.push_back(m);
            m = 1;
        }
    }
    ans.push_back(m);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}