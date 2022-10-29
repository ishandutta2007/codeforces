#ifdef AlCash
#define ASSERT(...) assert(__VA_ARGS__)
#else
#define ASSERT(...) true
#endif

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> inline T& smin(T& x, const T& y) { return x > y ? x = y : x; }
template <class T> inline T& smax(T& x, const T& y) { return x < y ? x = y : x; }
template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

template <class T> struct is_commutative { constexpr static bool value = true; };

template <class T> struct is_iterator {
  template <class U, typename enable_if<!is_convertible<U, const char*>::value, int>::type = 0>
  constexpr static auto has_indirection(int) -> decltype(*declval<U>(), bool()) { return true; }
  template <class> constexpr static bool has_indirection(long) { return false; }
  constexpr static bool value = has_indirection<T>(0);
};

using uint = unsigned int;
// Buffer size should be 2^12 or 2^13 for optimal performance with files.
const uint BUFFER_SIZE = 1 << 12;
// Maximum possible length of a string representing primitive type
// assuming we won't encounter huge double values.
const uint MAX_LENGTH = 1 << 7;

namespace Detail {
  struct Width { uint value; };
  struct Fill { char value; };
  struct Base { uint value; };
  struct Precision { uint value; };
  struct Delimiter { const char* value; };
}  // namespace Detail

Detail::Width setWidth(uint value = 0) { return {value}; }
Detail::Fill setFill(char value = ' ') { return {value}; }
Detail::Base setBase(uint value = 10) { assert(2 <= value && value <= 36); return {value}; }
Detail::Precision setPrecision(uint value = 9) { assert(value < MAX_LENGTH); return {value}; }
Detail::Delimiter setDelimiter(const char* value = " ") { return {value}; }

/******************************* input classes ********************************/
class InputDevice {
protected:
  const char* head;
  const char* tail;

  InputDevice(const char* head, const char* tail) : head(head), tail(tail), base(setBase().value) {}

  virtual void fillInput() = 0;

  inline char nextChar() {
    if (__builtin_expect(head >= tail, false)) fillInput();
    return *head++;
  }

  template <class I> int readUnsignedIntGeneral(I& arg, char c) {
    I value = 0;
    int length = 0;
    for (;; ++length, c = nextChar()) {
      if (isDigit(c)) c -= '0';
      else if (isUpper(c)) c -= 'A' - 10;
      else if (isLower(c)) c -= 'a' - 10;
      else c = base;
      if (c >= base) break;
      value = base * value + c;
    }
    arg = value;
    return --head, length;
  }

  template <class I> inline int readUnsignedInt(I& arg, char c) {
    if (__builtin_expect(base > 10, false)) return readUnsignedIntGeneral(arg, c);
    I value = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
      value = base * value + c - '0';
    arg = value;
    return --head, length;
  }

  template <class I> inline bool readSignedInt(I& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    typename make_unsigned<I>::type unsignedArg;
    if (readUnsignedInt(unsignedArg, c) == 0) return false;
    arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
    return true;
  }

  template <class F> bool readFloatingPoint(F& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    unsigned long long integerPart;
    if (readUnsignedInt(integerPart, c) == 0) return false;
    arg = static_cast<F>(integerPart);
    if (nextChar() == '.') {
      unsigned long long fractionalPart = 0;
      int fractionalLength = readUnsignedInt(fractionalPart, nextChar());
      if (fractionalLength > 0) {
        unsigned long long basePower = 1;
        for (; fractionalLength; --fractionalLength) basePower *= base;
        arg += static_cast<F>(fractionalPart) / basePower;
      }
    } else --head;
    if (negative) arg = -arg;
    return true;
  }

public:
  uint base;

  InputDevice(InputDevice const&) = delete;
  InputDevice& operator = (InputDevice const&) = delete;

  static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
  static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
  static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
  static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
  static inline bool isOneOf(char c, const char* str) { return strchr(str, c) != nullptr; }

  void putBack() { --head; }  // can be called only once directly after successfully reading a character

  inline bool readChar(char& arg) {
    if (__builtin_expect(head >= tail, false)) {
      fillInput();
      if (__builtin_expect(head >= tail, false)) return arg = '\0', false;
    }
    return arg = *head++, true;
  }

  template <class UnaryPredicate>
  inline char skipCharacters(UnaryPredicate isSkipped) {
    char c;
    do { c = nextChar(); } while (isSkipped(c));
    return c;
  }
  inline char skipCharacters() { return skipCharacters(isSpace); }

  template <class UnaryPredicate>
  inline int readString(char* arg, int limit, UnaryPredicate isTerminator, bool skip) {
    int charsRead = 0;
    if (skip) skipCharacters(isTerminator), --head;
    // put back first non-skipped character, reserve space for null character
    for (--limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), isTerminator) - head;
      arg = copy_n(head, chunkSize, arg);
      head += chunkSize;
      charsRead += chunkSize;
      if (chunkSize == 0 || head < tail) break;
    }
    return *arg = '\0', charsRead;
  }

  inline int readString(char* arg, int limit, const char* terminators, bool skip) {
    if (!*terminators) return readString(arg, limit, InputDevice::isSpace, skip);
    return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); }, skip);
  }

  // property setters
  inline bool read(Detail::Base newBase) { base = newBase.value; return true; }
  // primitive types
  inline bool read() { return true; }
  inline bool read(char& arg) { return readChar(arg); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
  bool>::type read(I& arg) { return readUnsignedInt(arg, skipCharacters()) > 0; }
  template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
  bool>::type read(I& arg) { return readSignedInt(arg, skipCharacters()); }
  template <class F> inline typename enable_if<is_floating_point<F>::value,
  bool>::type read(F& arg) { return readFloatingPoint(arg, skipCharacters()); }
  // characters skip
  inline bool read(const char& arg) { skipCharacters([arg](char c) { return arg != c; }); return true; }
  inline bool read(const char* arg) {
    if (*arg) skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
    else skipCharacters();
    return putBack(), true;
  }
  inline bool read(bool (*isSkipped)(char)) { skipCharacters(isSkipped); putBack(); return true; }
  // strings
  template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value,
  bool>::type read(char* arg, I limit, Terminator terminator, Ts&&... args) {
    readString(arg, static_cast<int>(limit), terminator, true);
    return read(forward<Ts>(args)...);
  }
  template <class I> inline typename enable_if<is_integral<I>::value,
  bool>::type read(char* arg, I limit) { return read(arg, limit, ""); }
  template <class... Ts>
  inline bool read(char* first, char* last, Ts&&... args) {
    return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
  }
  template <int N, class... Ts>
  inline bool read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
  template <class Terminator, class... Ts>
  inline bool read(string& arg, Terminator terminator, Ts&&... args) {
    for (int length = max(16, static_cast<int>(arg.capacity())), last = 0;; length = last += length) {
      arg.resize(last + length);
      int charsRead = readString(&arg[last], length + 1, terminator, last == 0);
      if (charsRead < length) {
        arg.resize(last + charsRead);
        return read(forward<Ts>(args)...);
      }
    }
  }
  inline bool read(string& arg) { return read(arg, ""); }
  // complex types and ranges
  template <class T1, class T2>
  inline bool read(pair<T1, T2>& arg) { return read(arg.first, arg.second); }
  template <class T>
  inline bool read(complex<T>& arg) {
    T real, imag;
    if (!read(real, imag)) return false;
    arg.real(real), arg.imag(imag);
    return true;
  }
  template <class T>
  inline bool read(vector<T>& arg) {
    uint n;
    if (!read(n)) return false;
    arg.resize(n);
    return read(arg.begin(), arg.end());
  }
  template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
  bool>::type read(Iterator first, Iterator last, Ts&&... args) {
    for (; first != last; ++first) if (!read(*first)) return false;
    return read(forward<Ts>(args)...);
  }
  template <class Iterator, class I, class... Ts>
  inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
  bool>::type read(Iterator first, I count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
  // generic forwarding
  template <class T>
  inline auto read(T& arg) -> decltype(arg.read(*this)) { return arg.read(*this); }
  template <class T0, class T1, class... Ts>
  inline typename enable_if<!is_iterator<T0>::value && !is_convertible<T0, char*>::value,
  bool>::type read(T0&& arg0, T1&& arg1, Ts&&... args) {
    return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);
  }
};

class InputFile : public InputDevice {
  FILE* file;
  bool lineBuffered;
  bool owner;
  char buffer[BUFFER_SIZE];

  void fillInput() override {
    head = buffer;
    *buffer = '\0';
    if (__builtin_expect(!lineBuffered, true)) {
      tail = head + fread(buffer, 1, BUFFER_SIZE, file);
    } else {
      tail = head;
      if (fgets(buffer, BUFFER_SIZE, file)) while (*tail) ++tail;
    }
  }

public:
  InputFile(FILE* file = stdin, bool lineBuffered = true, bool takeOwnership = false)
  : InputDevice(buffer, buffer) , file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
  InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}
  ~InputFile() { if (owner) fclose(file); }
};

// Picks up data appended to the string but doesn't handle reallocation.
class InputString : public InputDevice {
  void fillInput() override { while (*tail) ++tail; }

public:
  InputString(const string& s) : InputDevice(s.data(), s.data() + s.size()) {}
  InputString(const char* s) : InputDevice(s, s + strlen(s)) {}
};

/******************************* output classes *******************************/
class OutputDevice {
protected:
  char buffer[BUFFER_SIZE + MAX_LENGTH];
  char* output;
  char* end;
  bool separate;

  OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false)
  , width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value)
  , delimiter(setDelimiter().value) { computeBasePower(); }

  virtual void writeToDevice(uint count) = 0;

  inline void flushMaybe() {
    if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
      writeToDevice(BUFFER_SIZE);
      output = copy(buffer + BUFFER_SIZE, output, buffer);
    }
  }

  void computeBasePower() {
    basePower = 1;
    for (uint i = 0; i < precision; ++i) basePower *= base;
  }

  template <class I> inline char* writeUnsignedInt(I arg, char* last) {
    if (__builtin_expect(arg == 0, false)) *--last = '0';
    if (__builtin_expect(base == 10, true)) {
      for (; arg; arg /= 10) *--last = '0' + arg % 10;
    } else for (; arg; arg /= base) {
      I digit = arg % base;
      *--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
    }
    return last;
  }

  template <class I> inline char* writeSignedInt(I arg, char* last) {
    auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
    if (arg < 0) {
      last = writeUnsignedInt(~unsignedArg + 1, last);
      *--last = '-';
      return last;
    }
    return writeUnsignedInt(unsignedArg, last);
  }

  template <class F> char* writeFloatingPoint(F arg, char* last) {
    bool negative = signbit(arg);
    if (negative) arg = -arg;
    if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
    else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
    else {
      auto integerPart = static_cast<unsigned long long>(arg);
      auto fractionalPart = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
      if (fractionalPart >= basePower) ++integerPart, fractionalPart = 0;
      char* point = last - precision;
      if (precision > 0) {
        ::fill(point, writeUnsignedInt(fractionalPart, last), '0');
        *--point = '.';
      }
      last = writeUnsignedInt(integerPart, point);
    }
    if (negative) *--last = '-';
    return last;
  }

  inline int writeT(char* first) {
    int delimiterLength = separate ? writeDelimiter() : 0;
    separate = true;
    uint charsWritten = static_cast<uint>(end - first);
    if (__builtin_expect(charsWritten < width, false))
      charsWritten += writeFill(width - charsWritten);
    output = copy(first, end, output);
    flushMaybe();
    return delimiterLength + static_cast<int>(charsWritten);
  }

  inline int writeFill(uint count) {
    int charsWritten = static_cast<int>(count);
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = fill;
      else output = fill_n(output, count, fill);
    } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = fill_n(output, chunkSize, fill);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
    }
    return charsWritten;
  }

public:
  uint width;
  char fill;
  uint base;
  uint precision;
  unsigned long long basePower;
  string delimiter;

  OutputDevice(OutputDevice const&) = delete;
  OutputDevice& operator = (OutputDevice const&) = delete;
  virtual ~OutputDevice() {};

  inline int writeChar(char arg) { separate = false; *output++ = arg; flushMaybe(); return 1; }

  inline int writeString(const char* arg, size_t length, bool checkWidth = true) {
    separate = false;
    uint count = static_cast<uint>(length);
    int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = *arg;
      else output = copy_n(arg, count, output);
    } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = copy_n(arg, chunkSize, output);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
      arg += chunkSize;
    }
    return charsWritten;
  }

  inline int writeDelimiter() { return writeString(delimiter.c_str(), delimiter.size(), false); }

  inline void flush() {
    writeToDevice(static_cast<uint>(output - buffer));
    output = buffer;
  }

  // property setters
  inline int write(Detail::Width newWidth) { width = newWidth.value; return 0; }
  inline int write(Detail::Fill newFill) { fill = newFill.value; return 0; }
  inline int write(Detail::Base newBase) { base = newBase.value; computeBasePower(); return 0; }
  inline int write(Detail::Precision newPrecision) {
    precision = newPrecision.value; computeBasePower(); return 0;
  }
  inline int write(Detail::Delimiter newDelimiter) { delimiter = newDelimiter.value; return 0; }
  // primitive types
  inline int write() { return 0; }
  inline int write(char arg) { return writeChar(arg); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
  int>::type write(I arg) { return writeT(writeUnsignedInt(arg, end)); }
  template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
  int>::type write(I arg) { return writeT(writeSignedInt(arg, end)); }
  template <class F> inline typename enable_if<is_floating_point<F>::value,
  int>::type write(F arg) { return writeT(writeFloatingPoint(arg, end)); }
  // complex types
  inline int write(const char* arg) { return writeString(arg, strlen(arg)); }
  template <int N>
  inline int write(char (&arg)[N]) { return writeString(arg, strlen(arg)); }
  inline int write(const string& arg) { return writeString(arg.c_str(), arg.size()); }
  template <class T1, class T2>
  inline int write(const pair<T1, T2>& arg) {
    int charsWritten = write(arg.first);
    charsWritten += writeDelimiter();
    return charsWritten + write(arg.second);
  }
  template <class T>
  inline int write(const complex<T>& arg) { return write(real(arg), imag(arg)); }
  // ranges
  template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
  int>::type write(Iterator first, Iterator last, Ts&&... args) {
    int charsWritten = 0;
    for (; first != last; charsWritten += ++first == last ? 0 : writeDelimiter()) charsWritten += write(*first);
    return charsWritten + write(forward<Ts>(args)...);
  }
  template <class Iterator, class I, class... Ts>
  inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
  int>::type write(Iterator first, I count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
  // generic forwarding
  template <class T>
  inline auto write(const T& arg) -> decltype(arg.write(*this)) { return arg.write(*this); }
  template <class T0, class T1, class... Ts> inline typename enable_if<!is_iterator<T0>::value,
  int>::type write(T0&& arg0, T1&& arg1, Ts&&... args) {
    int charsWritten = write(forward<T0>(arg0));
    return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);
  }
};

class OutputFile : public OutputDevice {
  FILE* file;
  bool owner;

  void writeToDevice(uint count) override {
    fwrite(buffer, 1, count, file);
    fflush(file);
  }

public:
  OutputFile(FILE* file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
  OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
  ~OutputFile() override { flush(); if (owner) fclose(file); }
};

class OutputString : public OutputDevice {
  string& str;

  void writeToDevice(uint count) override { str.append(buffer, count); }

public:
  OutputString(string& str) : OutputDevice(), str(str) {}
  ~OutputString() override { flush(); }
};

//unique_ptr<InputDevice> input;
unique_ptr<InputFile> input;
//unique_ptr<OutputDevice> output;
unique_ptr<OutputFile> output;

template <class... Ts> inline bool read(Ts&&... args) { return input->read(forward<Ts>(args)...); }
template <class... Ts> inline int write(Ts&&... args) { return output->write(forward<Ts>(args)...); }
template <class... Ts> inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }
void flush() { output->flush(); }

/*******************************************************************************
 * Read returns true if all the arguments were successfully read. Parameters:
 * - setBase(uint): base for integer and floating point numbers
 * Single variable of one of the following types:
 * - char, standard integer and floating point types
 * - pair, complex
 * - vector (size and then the elements)
 * Characters skip:
 * - char: skip until the given character is encountered and read it
 * - const char*: skip all the characters from the string
 * - predicate: skip all the characters satisfying the predicate
 * Strings: read until character limit is reached or termination character
 *   is found (one of the characters in a given string or defined by predicate,
 *   isspace by default)
 * - char (&)[N], terminator
 * - char*, int limit, terminator
 * - string&, terminator
 * Ranges:
 * - Iterator first, Iterator last
 * - Iterator first, int count
 *******************************************************************************
 * Write returns number of characters written. Parameters:
 * - setWidth(uint): minimum width of a single element to write (except char)
 * - setFill(char): character prepended to an element until set width is reached
 * - setBase(uint): base for integer and floating point numbers
 * - setPrecision(uint): number of digits after the decimal point
 * - setDelimiter(const char*): delimiter automatically inserted
 *   between elements that are not strings or characters
 * Single variable of one of the following types:
 * - char, standard integer and floating point types
 * - string, const char*
 * - pair, complex
 * Ranges:
 * - Iterator first, Iterator last
 * - Iterator first, int count
 ******************************************************************************/

template <class T> struct Shift {
  static inline T f(const T& x, int offset) { return x; }
};
template <class T> struct Combine {
  static inline T f(const T& lhs, const T& rhs, int lhSize, int rhSize) {
    return lhs + (rhs << lhSize);
  }
};
template <class T> struct Reverse {
  static inline void f(T& dst, int size) {};
};
template <class T, class M> struct Modify {
  static inline void f(T& dst, const M& src, int factor) { dst += src; }
};
template <class R, class T> struct Query {
  static inline R f(T& x) { return static_cast<R>(x); }
};

template <class T>
inline T operator << (const T& x, int offset) { return Shift<T>::f(x, offset); }
template <class T>
inline T combine(const T& lhs, const T& rhs, int lhSize, int rhSize) {
  return Combine<T>::f(lhs, rhs, lhSize, rhSize);
}
template <class T>
inline void reverse(T& dst, int size) { Reverse<T>::f(dst, size); }
template <class T, class M>
inline void modify(T& dst, const M& src, int factor) {
  Modify<T, M>::f(dst, src, factor);
}
template <class R, class T>
inline R query(T& x) { return Query<R, T>::f(x); }

#define WRAPPER(Name, defaultValue, maxValue) \
template <class T> struct Name; \
namespace std { \
template <class T> struct numeric_limits<Name<T>> { \
constexpr static T max() { return maxValue; } \
}; \
} \
template <class T> struct Name { \
T value; \
constexpr inline Name(const T& value = defaultValue) : value(value) {} \
explicit inline operator T() const { return value; } \
explicit inline operator bool() const { return value != defaultValue; } \
inline bool read(InputDevice& input) { return input.read(value); } \
inline int write(OutputDevice& output) const { return output.write(value); } \
friend inline bool operator == (const Name& lhs, const Name& rhs) { \
return lhs.value == rhs.value; } \
friend inline bool operator != (const Name& lhs, const Name& rhs) { \
return lhs.value != rhs.value; }

WRAPPER(Sum, 0, numeric_limits<T>::max() / 2)
friend inline bool operator < (const Sum& lhs, const Sum& rhs) {
  return lhs.value < rhs.value; }
inline void operator += (const Sum& other) { value += other.value; }
inline void operator -= (const Sum& other) { value -= other.value; }
friend inline Sum operator + (const Sum& lhs, const Sum& rhs) {
  return lhs.value + rhs.value; }
friend inline Sum operator - (const Sum& lhs, const Sum& rhs) {
  return lhs.value - rhs.value; }
};

WRAPPER(Max, -numeric_limits<T>::max(), numeric_limits<T>::max())
friend inline bool operator < (const Max& lhs, const Max& rhs) {
  return lhs.value < rhs.value; }
inline void operator += (const Max& other) { smax(value, other.value); }
inline void operator += (const Sum<T>& other) { value += other.value; }
friend inline Max operator + (const Max& lhs, const Max& rhs) {
  return max(lhs.value, rhs.value); }
};

#undef WRAPPER

template <class T, class M>
class SegmentTreeRooted {
#define FP forward<Ps>(params)...
  template <class U, class P> constexpr static auto has_cascading(int)
  -> decltype(U().cascade(true, P()), bool()) { return true; }
  template <class, class>
  constexpr static bool has_cascading(long) { return false; }

  constexpr static const bool CASCADE_M = has_cascading<T, M>(0);
  constexpr static const bool COMMUTATIVE = is_commutative<M>::value;

  int n;       // number of elements in the array = leaves in the tree
  int height;  // height of the tree: 2 ^ height >= n otherwise
  int width;   // node size on the current level, always a power of 2
  vector<T> data;
  vector<M> delta;

  inline int check(int i) const {
    ASSERT(0 <= i && i < n);
    return i + (1 << height);
  }

  template <bool LEAVES> inline void check(int& l, int& r) const {
    ASSERT(0 <= l && l < r && r <= n);
    if (LEAVES) l += 1 << height, r += (1 << height) - 1;
  }

  inline int child(int i, int right) const { return i << 1 | right; }
  //if PERSISTENT
  //inline int child(int i, int right) const {
  //  return right ? nodes[i].right : node[i].left; }

  template <class P, class U = T> typename enable_if<has_cascading<U, P>(0),
  void>::type inline cascadeInplace(int i, int right, int lhSize, P& param) {
    data[i].cascade(right, param);
  }
  void inline cascadeInplace(int i, int right, long lhSize, M& value) {
    if (right) value = value << static_cast<int>(lhSize);
  }
  template <class P>
  void inline cascadeInplace(int i, int right, long, P&& param) {}

  template <class P, class U = T>
  typename enable_if<has_cascading<U, P>(0) || is_same<P, M>::value, P>::type
  inline cascade(int i, int right, int lhSize, P param) {
    cascadeInplace(i, right, lhSize, param);
    return param;
  }
  template <class P>
  inline auto cascade(int i, int right, long lhSize, P&& param) ->
  decltype(forward<P>(param)) { return forward<P>(param); }

  inline void leaveNode(int& i, int right, int lhSize) {
    i = child(i, right);
  }
  template <class P, class... Ps>
  inline void leaveNode(int& i, int right, int lhSize, P&& p, Ps&&... params) {
    cascadeInplace(i, right, lhSize, p);
    leaveNode(i, right, lhSize, forward<Ps>(params)...);
  }

  inline void compute(int i) {
    data[i] = combine(data[child(i, 0)], data[child(i, 1)], width, width);
    if (COMMUTATIVE && !CASCADE_M) ::modify(data[i], delta[i], width << 1);
  }

  // if persistent i >>= 1 becomes --i or i -= 1 + (i&1)
  inline void computePath(int i, int i0) {
    for (; i != i0; compute(i >>= 1), width <<= 1);
  }

  inline void apply(int i, const M& value) {
    ::modify(data[i], value, width);
    if (i < static_cast<int>(delta.size())) delta[i] += value;
  }

  // don't push in query and binarySearch if PERSISTENT && COMMUTATIVE
  inline void pushNode(int i) {
    apply(child(i, 0), cascade(i, 0, width, delta[i]));
    apply(child(i, 1), cascade(i, 1, width, delta[i]));
    delta[i] = M();
  }

  void modifyPoint(int i, const M& value) {  // commutative
    for (i = check(i); i; i >>= 1) ::modify(data[i], value, 1);
  }

  void modifyPoint(int i, const T& value) {  // non-commutative ?or persistent
    for (::modify(data[i = check(i)], value, 1); i >>= 1; compute(i));
  }

  void modifyRight(int i, int h, int r, M value) {
    int i0 = i;
    for (; !((r + 1) >> h--); r &= ~(1 << h)) {
      width >>= 1, pushNode(i);
      if (r >> h) apply(child(i, 0), cascade(i, 0, width, value));
      leaveNode(i, r >> h, width, value);
    }
    apply(i, value);
    computePath(i, i0);
  }

  template <int LOWER_BOUND, class Compare, class... Ps>
  int binarySearch(Compare compare, Ps&&... params) {
    int i = 1;
    if (!compare(data[i], forward<Ps>(params)...)) return -1;
    for (width = height == 0 ? 0 : 1 << (height - 1); width; width >>= 1) {
      pushNode(i);
      leaveNode(i, compare(data[child(i, LOWER_BOUND)], forward<Ps>(params)...)
                == LOWER_BOUND, width, forward<Ps>(params)...);
    }
    return i - (1 << height);
  }

public:
  using DataType = T;
  using ModificationType = M;

  SegmentTreeRooted(int size = 0) { init(size); }

  void init(int size) {
    n = size;
    height = n == 0 ? 0 : sizeof(n) * 8 - __builtin_clz(n - 1);
    int nodeCount = (1 << height) + n + (n & 1);
    data.assign(nodeCount, T());
    delta.assign((nodeCount + (nodeCount & 2)) / 2, M());
  }

  void clear() {
    data = {};
    delta = {};
  }

  int size() const { return n; }

  T& operator [] (int i) { return data[check(i)]; }
  const T& operator [] (int i) const { return data[check(i)]; }

  void build(int l, int r) {
    check<true>(l, r);
    for (width = 1; r >>= 1, l >>= 1; width <<= 1)
      for (int i = r; i >= l; --i) compute(i);
  }
  void build() { build(0, n); }

  template <bool RANGE = true>
  void push(int l, int r) {
    check<true>(l, r);
    int h = height;
    for (width = 1 << (h - 1); h; --h, width >>= 1) {
      if (RANGE) {
        for (int i = l >> h; i <= r >> h; ++i) pushNode(i);
      } else {
        pushNode(l >> h);
        if ((l ^ r) >> h) pushNode(r >> h);
      }
    }
  }
  void push() { push<true>(0, n); }

  void modify(int l, int r, const M& value) {
    if (!COMMUTATIVE) push<false>(l, r);
    check<true>(l, r);
    int sizeL = 0, sizeR = 0, sizeLR = r - l;
    for (++r, width = 0; l < r; l >>= 1, r >>= 1) {
      if (sizeL) compute(l - 1);
      if (sizeR) compute(r);
      width == 0 ? width = 1 : width <<= 1;
      if (l & 1) apply(l++, value << sizeL), sizeL += width;
      if (r & 1) sizeR += width, apply(--r, value << (sizeLR - sizeR));
    }
    for (l -= !!sizeL, r -= !sizeR; l < r; l >>= 1, r >>= 1, width <<= 1) {
      compute(l);
      compute(r);
    }
    for (; l; l >>= 1, width <<= 1) compute(l);
  }

//  template <class... Ps>
//  T query(Ps&&... params) { return query<T>(forward<Ps>(params)...); }

  template <class Compare, class... Ps>
  int lowerBound(Compare compare, Ps&&... params) {
    return binarySearch<0>(compare, forward<Ps>(params)...);
  }

  template <class Compare, class... Ps>
  int upperBound(Compare compare, Ps&&... params) {
    return binarySearch<1>(compare, forward<Ps>(params)...);
  }
};

int main() {
#ifdef AlCash
  input.reset(new InputFile("input.txt"));
  //input.reset(new InputFile());
  output.reset(new OutputFile());
  //output.reset(new OutputFile("output.txt"));
#else
  input.reset(new InputFile(stdin, false));
  //input.reset(new InputFile());
  output.reset(new OutputFile());
#endif

  int n;
  read(n);
  vector<int> p(n), t(n), x(n), u(n);
  REP(i, n) {
    read(p[i], t[i]);
    if (t[i] == 1) read(x[i]);
    u[p[i] - 1] = i;
  }
  SegmentTreeRooted<Max<int>, Sum<int>> tree(n);
  REP(i, n) tree[i] = 0;
  tree.build();
  REP(i, n) {
    tree.modify(0, p[i], t[i] == 1 ? 1 : -1);
    int j = tree.upperBound([](Max<int> m) { return m.value >= 1; });
    writeln(j == -1 ? j : x[u[j]]);
  }

#ifdef AlCash
  flush();
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}