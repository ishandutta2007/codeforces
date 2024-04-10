#include <iostream>
#include <algorithm>
#include <math.h>
#include <algorithm>

using namespace std;

int a[30];

bool check34(){
	if (a[13] != a[14] || a[14] != a[15] || a[15] != a[16])
		return false;
	if (a[17] != a[18] || a[18] != a[19] || a[19] != a[20])
		return false;
	if (a[6] != a[8] || a[2] != a[4] || a[10] != a[12] || a[21] != a[23])
		return false;
	if (a[5] != a[7] || a[1] != a[3] || a[9] != a[11] || a[22] != a[24])
		return false;
	bool pad = true, sa = true;
	if (a[6] != a[3] || a[4] != a[22] || a[21] != a[9] || a[10] != a[5])
		pad = false;
	if (a[6] != a[9] || a[10] != a[22] || a[21] != a[3] || a[4] != a[5])
		sa = false;
	if (pad || sa)
		return true;
	return false;

}

bool check25(){
	if (a[5] != a[6] || a[6] != a[7] || a[7] != a[8])
		return false;
	if (a[21] != a[22] || a[22] != a[23] || a[23] != a[24])
		return false;
	if (a[17] != a[19] || a[3] != a[4] || a[14] != a[16] || a[9] != a[10])
		return false;
	if (a[18] != a[20] || a[1] != a[2] || a[13] != a[15] || a[11] != a[12])
		return false;
	bool pad = true, sa = true;
	if (a[17] != a[2] || a[4] != a[13] || a[14] != a[12] || a[9] != a[18])
		pad = false;
	if (a[17] != a[12] || a[10] != a[15] || a[16] != a[1] || a[4] != a[18])
		sa = false;
	if (pad || sa)
		return true;
	return false;
}

bool check16(){
    if (a[1] != a[2] || a[2] != a[3] || a[3] != a[4])
        return false;
    if (a[9] != a[10] || a[10] != a[11] || a[11] != a[12])
        return false;
    if (a[5] != a[6] || a[17] != a[18] || a[21] != a[22] || a[13] != a[14])
        return false;
    if (a[15] != a[16] || a[7] != a[8] || a[19] != a[20] || a[23] != a[24])
        return false;
	bool sage = true, padsa = true;
	if (a[6] != a[16] || a[14] != a[24] || a[22] != a[20] || a[18] != a[8])
		sage = false;
	if (a[6] != a[20] || a[18] != a[24] || a[22] != a[16] || a[14] != a[8])
		padsa = false;
	if (sage || padsa)
		return true;
	return false;
}


int main(){
	for (int i = 1; i <= 24; i++)
		cin >> a[i];
	if (check16() || check25() || check34())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}