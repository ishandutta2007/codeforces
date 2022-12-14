#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 500;
int lef[maxn], a[maxn], rig[maxn];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    lef[0] = -1;
    for (int i = 1; i < n; i++){
        lef[i] = i - 1;
        if (a[i - 1] % a[i] != 0)
            lef[i] = i - 1;
        else {
            while (lef[i] != -1 && a[lef[i]] % a[i] == 0){
                lef[i] = lef[lef[i]];
            }
        }
    }
    rig[n - 1] = n;
    for (int i = n - 2; i >= 0; i--){
        rig[i] = i + 1;
        if (a[i + 1] % a[i] != 0)
            rig[i] = i + 1;
        else {
            while (rig[i] != n && a[rig[i]] % a[i] == 0){
                rig[i] = rig[rig[i]];
            }
        }
    }
    int leng = 0, cnt = 0;
    set <int> v;
    for (int i = 0; i < n; i++)
        leng = max(leng, rig[i] - lef[i] - 2);
    for (int i = 0; i < n; i++)
        if (rig[i] - lef[i] - 2 == leng){
            v.insert(lef[i] + 2);
        }
    cout << v.size() << " " << leng << endl;
    for (auto it : v)
        cout << it << " ";
}