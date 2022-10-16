#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sir;
    int n;
    cin >> n >> sir;

    int ans = 0;

    for (int i = 0; i < n; ++ i) {
        int up = 0, left = 0;
        for (int j = i; j < n; ++ j) {
            if (sir[j] == 'U')
                up ++;
            else if (sir[j] == 'D')
                up --;
            else if (sir[j] == 'R')
                left --;
            else
                left ++;
        if (!up && !left)
            ++ ans;
        }

    }

    cout << ans << '\n';
    return 0;
}