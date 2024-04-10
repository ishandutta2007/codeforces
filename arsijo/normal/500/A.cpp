#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ar[n];
    for(int i = 0; i < n-1; i++){
        cin >> ar[i];
    }
    int pos = 0;
    m--;
    while (pos < m){
        pos+= ar[pos];
    }
    if (pos == m){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}