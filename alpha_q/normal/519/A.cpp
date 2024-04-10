#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <iterator>
#include <bitset>

#define FOR(it, from, to) for (int it = from; it < to; it++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define in(vec, elem) vec.push_back(elem)

using namespace std;

main()
{
    int white = 0, black = 0;
    FOR (i, 0, 64) {
        char in; cin >> in;
        if (in == 'Q') white += 9;
        else if (in == 'R') white += 5;
        else if (in == 'B') white += 3;
        else if (in == 'N') white += 3;
        else if (in == 'P') white += 1;
        else if (in == 'q') black += 9;
        else if (in == 'r') black += 5;
        else if (in == 'b') black += 3;
        else if (in == 'n') black += 3;
        else if (in == 'p') black += 1;
    }
    if (white > black) cout << "White";
    else if (white < black) cout << "Black";
    else cout << "Draw";
}