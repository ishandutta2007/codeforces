#include <iostream>

const long long MAX_ARG = 577350270; /* Maximum argument to the hexstart function */

using namespace std;

long long mvx [6] = {-1, -2, -1,  1, 2, 1};
long long mvy [6] = { 2,  0, -2, -2, 0, 2};

long long hexstart (long long n) { /* Amount of moves after which hexframe n is reached */
  return 3 * n * (n + 1) + 1;
}

long long hexid (long long key, long long start, long long end) {
  if (end - start == 1) {
    return start;
  }

  if (hexstart((start + end) / 2) <= key &&
      key < hexstart((start + end) / 2 + 1)) {
    return (start + end) / 2;
  } else if (key < hexstart((start + end) / 2)) {
    return hexid(key, start, (start + end) / 2);
  } else {
    return hexid(key, (start + end) / 2 + 1, end);
  }
}

long long size (long long hxid) { /* Size of hexframe hxid */
  return (hxid + 1) * 6;
}

long long startx (long long hxid) { /* Starting point of hexframe hxid */
  return hxid * 2 + 1;
}

int main () {
  long long movec;
  cin >> movec;

  if (movec == 0) {
    cout << 0 << " " << 0 << endl;
  } else {
    long long hxid = hexid(movec, -1, MAX_ARG);
    long long x = startx(hxid), y = 2;
    long long memno = movec - hexstart(hxid);
    long long section = memno / (size(hxid) / 6);
    for (int i = 0; i < section; i++) {
      x += mvx[i] * ((size(hxid) / 6) - 1);
      y += mvy[i] * ((size(hxid) / 6) - 1);
      x += mvx[i + 1];
      y += mvy[i + 1];
    }
    long long secmemno = memno - section * (size(hxid) / 6);
    x += mvx[section] * secmemno;
    y += mvy[section] * secmemno;
    cout << x << " " << y << endl;
  }
}