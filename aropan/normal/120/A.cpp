#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    string s;
    int x;


    cin >> s >> x;

    puts(s == "front" && x == 1 || s == "back" && x == 2? "L" : "R");

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}