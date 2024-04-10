#include <iostream>
#include <vector>
using namespace std;

int a;
int lastZ;

int main() {
    int nb;
    cin >> nb;
    
    vector<int> nbs, sol(nb, 1000 * 1000);
    
    lastZ = -1000 * 1000;
    for(int i = 0;i < nb;i++) {
        cin >> a;
        nbs.push_back(a);
        if(a == 0)
            lastZ = i;
        sol[i] = i - lastZ;
    }
    
    lastZ = 1000 * 1000;
    for(int i = nb - 1;i >= 0;i--) {
        if(nbs[i] == 0)
            lastZ = i;
        sol[i] = min(sol[i], lastZ - i);
    }
    
    for(int i = 0;i < nb;i++)
        cout << sol[i] << " ";
}