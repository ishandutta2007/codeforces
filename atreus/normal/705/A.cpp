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

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1)
        return cout << "I hate it", 0;
    for (int i = 1; i < n; i++){
        if (i % 2 == 1)
            cout << "I hate that ";
        else
            cout << "I love that ";
    }
    if (n % 2 == 1)
        cout << "I hate it";
    else
        cout << "I love it";
}