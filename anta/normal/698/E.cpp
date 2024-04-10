#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Date {
	typedef int Integer; Integer offset;
	static const int days[12], dayscumsum[13], dayscumsuml[13];
	struct YMD {
		Integer Y; int M, D;
		YMD(Integer Y_, int M_, int D_) : Y(Y_), M(M_), D(D_) {}
	};
	Date() : offset(0) {}
	explicit Date(Integer offset_) : offset(offset_) {}
	Date(Integer Y, int M, int D) : offset(toOffset(Y, M, D)) {}

	static bool isLeapYear(Integer Y) {
		return Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0);
	}
	static int getDays(Integer Y, int M) {
		return days[M - 1] + (M == 2 && isLeapYear(Y));
	}
	static Integer toOffset(Integer y, int m, int d) {
		if(m <= 2) y --, m += 12;
		return y * 365 + div(y, 4) - div(y, 100) + div(y, 400) + 153 * (m + 1) / 5 + d - 428;
	}
	void getYearMonthDay(Integer &Y, int &M, int &D) const {
		Integer a = offset - 1, quadcent = div(a, 146097);
		Integer b = a - quadcent * 146097, cent = min(b / 36524, Integer(3));
		Integer c = b - cent * 36524, quad = c / 1461;
		Integer d = c - quad * 1461, y = min(d / 365, Integer(3));
		Y = quadcent * 400 + cent * 100 + quad * 4 + y + 1;
		int yd = (int)(d - y * 365 + 1);
		fromOrdinalDate(Y, yd, M, D);
	}
	static void fromOrdinalDate(const Integer &Y, int yd, int &M, int &D) {
		const int *cumsum = isLeapYear(Y) ? dayscumsuml : dayscumsum;
		M = upper_bound(cumsum, cumsum + 13, yd - 1) - cumsum;
		D = yd - cumsum[M - 1];
	}

	Integer getYear() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return Y; }
	int getMonth() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return M; }
	int getDay() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return D; }
	int getDayOfWeek() const { return offset % 7; }

	Date operator+(Integer that) const { return Date(offset + that); }
	Date &operator+=(Integer that) { offset += that; return *this; }
	Integer operator-(const Date &that) const { return offset - that.offset; }

	bool operator==(const Date &that) const { return offset == that.offset; }
	bool operator!=(const Date &that) const { return offset != that.offset; }
	bool operator< (const Date &that) const { return offset <  that.offset; }
	bool operator> (const Date &that) const { return offset >  that.offset; }
	bool operator<=(const Date &that) const { return offset <= that.offset; }
	bool operator>=(const Date &that) const { return offset >= that.offset; }

	friend ostream &operator<<(ostream &o, const Date &that) {
		Date::Integer Y; int M, D; that.getYearMonthDay(Y, M, D);
		return o << Y << "/" << M << "/" << D;
	}
private:
	static inline Integer div(Integer x, int y) { return x / y - (x % y != 0 && x < 0); };
};
const int Date::days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int Date::dayscumsum[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
const int Date::dayscumsuml[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };

void decompose(long long epoc, int &Y, int &M, int &D, int &W, int &h, int &m, int &s) {
	const int startOffset = Date::toOffset(1970, 1, 1);
	Date date(startOffset + (int)(epoc / (24 * 60 * 60)));
	date.getYearMonthDay(Y, M, D);
	W = date.getDayOfWeek();
	int time = epoc % (24 * 60 * 60);
	h = time / (60 * 60), m = time / 60 % 60, s = time % 60;
}

int main() {
	int s; int m; int h;
	while(~scanf("%d%d%d", &s, &m, &h)) {
		vector<int> validTimes;
		rep(hh, 24) rep(mm, 60) rep(ss, 60) {
			if((s == -1 || ss == s) && (m == -1 || mm == m) && (h == -1 || hh == h))
				validTimes.push_back(hh * 60 * 60 + mm * 60 + ss);
		}
		int W; int D; int M;
		scanf("%d%d%d", &W, &D, &M);
W %= 7;
		int Q;
		scanf("%d", &Q);
		rep(ii, Q) {
			long long epoc;
			scanf("%lld", &epoc);
			++ epoc;
			int qY, qM, qD, qW, qh, qm, qs;
			decompose(epoc, qY, qM, qD, qW, qh, qm, qs);
			while(1) {
				bool dayok = (W == -1 && D == -1) || (W != -1 && qW == W) || (D != -1 && qD == D);
				bool monthok = M == -1 || M == qM;
				if(dayok && monthok) {
					int time = epoc % (24 * 60 * 60);
					if(time <= validTimes.back()) {
						int ntime = *lower_bound(validTimes.begin(), validTimes.end(), time);
						epoc = epoc - time + ntime;
						break;
					}
				}
				if(!monthok && qD < 28) {
					epoc += (28 - qD) * 24 * 60 * 60;
				} else {
					epoc += 24 * 60 * 60;
				}
				epoc = epoc / (24 * 60 * 60) * (24 * 60 * 60);
				decompose(epoc, qY, qM, qD, qW, qh, qm, qs);
			}
			printf("%lld\n", epoc);
		}
	}
	return 0;
}