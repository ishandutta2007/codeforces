/*
######################################################################
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
#@@@      @@@@@@   @@@@@@       @@@@@     @@@@@@     @@@@    @@@@  @@#
#@@   @@@@@@@@@  @  @@@@@  @@@@  @@@  @@@  @@@@  @@@  @@@  @  @@@  @@#
#@@@      @@@@  @@@  @@@@       @@@  @@@@@  @@  @@@@@  @@  @@  @@  @@#
#@@@@@@@   @@         @@@  @@@@  @@@  @@@  @@@@  @@@  @@@  @@@  @  @@#
#@@@      @@  @@@@@@@  @@        @@@@     @@@@@@     @@@@  @@@@    @@#
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
######################################################################
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;
int a[maxn];

int main (){
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 145; i++){
        a[i] = a[i - 1] + i + 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < 145; i++){
        if (n < a[i])
            return cout << i, 0;
        n -= a[i];
    }
}