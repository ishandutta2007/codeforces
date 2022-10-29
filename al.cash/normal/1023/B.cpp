// Powered by ACHelper (https://github.com/AlCash07/ACHelper)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

namespace ac {

struct io_tag {};

/// caide keep
struct binary_io_tag : io_tag {};
/// caide keep
struct text_io_tag   : io_tag {};

template <class Device>
struct io_traits {
    /// caide keep
    static constexpr bool binary = std::is_base_of<binary_io_tag, typename Device::category>::value;
    /// caide keep
    static constexpr bool text   = std::is_base_of<text_io_tag,   typename Device::category>::value;

    static_assert(!binary || !text, "device can't be binary and text at the same time");
};

#define EXPECT_TRUE(condition) __builtin_expect((condition), true)
#define EXPECT_FALSE(condition) __builtin_expect((condition), false)

static inline constexpr bool is_space(char c) {
    return static_cast<unsigned char>(c - '\t') < 5 || c == ' ';
}

static inline constexpr bool is_digit(char c) { return static_cast<unsigned char>(c - '0') < 10; }

static inline constexpr bool is_upper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }

static inline constexpr bool is_lower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }

template <bool B, typename T = void>
using enable_if_t = typename std::enable_if<B, T>::type;

template <bool B, typename T, typename F>
using conditional_t = typename std::conditional<B, T, F>::type;

template <typename T>
using remove_reference_t = typename std::remove_reference<T>::type;

// TODO: switch to std after C++17.
/// caide keep
template <typename... Ts>
struct make_void {
    /// caide concept
    typedef void type;
};

template <typename... Ts> using void_t = typename make_void<Ts...>::type;

// TODO: switch to std after C++17.
template <bool B>
using bool_constant = std::integral_constant<bool, B>;

template <class T>
struct is_signed_int : bool_constant<std::is_signed<T>::value && std::is_integral<T>::value> {};

/// caide keep
template <class T>
using dereference_t = decltype(*std::declval<T>());

namespace detail {

template <class T, class = void>
struct is_iterator_impl : std::false_type {};

/// caide keep
template <class T>
struct is_iterator_impl<T, void_t<dereference_t<T>>> : std::true_type {};

template <class T, bool = false>
struct is_const_iterator_impl : std::false_type {};

/// caide keep
template <class T>
struct is_const_iterator_impl<T, true> : std::is_const<remove_reference_t<dereference_t<T>>> {};

template <class T, class = void>
struct has_iterator_category_impl : std::false_type {};

/// caide keep
template <class T>
struct has_iterator_category_impl<T, void_t<typename T::iterator_category>> : std::true_type {};

}

/// caide keep
template <class T>
struct is_iterator : detail::is_iterator_impl<T> {};

/// caide keep
template <class T>
struct is_const_iterator : detail::is_const_iterator_impl<T, is_iterator<T>::value> {};

template <class T>
struct is_non_const_iterator
    : bool_constant<is_iterator<T>::value && !is_const_iterator<T>::value> {};

namespace detail {

template <class Device, class UInt>
inline int read_unsigned_int_general(Device& in, UInt& arg, char c) {
    auto base   = in.get_base();
    UInt value  = 0;
    int  length = 0;
    for (;; c = in.read_char()) {
        if (is_digit(c)) c -= '0';
        else if (is_upper(c)) c -= 'A' - 10;
        else if (is_lower(c)) c -= 'a' - 10;
        else c = static_cast<char>(base);
        if (c >= base) break;
        value = base * value + c;
        ++length;
    }
    in.put_back();
    arg = value;
    return length;
}

template <class Device, class Int>
inline int read_unsigned_int(Device& in, Int& arg, char c) {
    auto base = in.get_base();
    if (EXPECT_FALSE(base > 10)) return read_unsigned_int_general(in, arg, c);
    Int value  = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; c = in.read_char()) {
        value = base * value + c - '0';
        ++length;
    }
    in.put_back();
    arg = value;
    return length;
}

template <class Device, class UnaryPredicate>
inline char skip_characters(Device& in, UnaryPredicate is_skipped) {
    char c;
    do { c = in.read_char(); } while (is_skipped(c));
    return c;
}

template <class Device>
inline char skip_characters(Device& in) { return skip_characters(in, is_space); }

}

template <class Device, class Int>
inline enable_if_t<is_signed_int<Int>::value && !std::is_same<Int, char>::value, bool> read(
    text_io_tag, Device& in, Int& arg) {
    char c = detail::skip_characters(in);
    bool negative = c == '-';
    if (negative) c = in.read_char();
    typename std::make_unsigned<Int>::type unsigned_arg;
    if (detail::read_unsigned_int(in, unsigned_arg, c) == 0) return false;
    arg = negative ? ~static_cast<Int>(unsigned_arg - 1) : static_cast<Int>(unsigned_arg);
    return true;
}

template <class Device, class T0, class T1, class... Ts>
inline enable_if_t<!is_non_const_iterator<T0>::value, bool> read(io_tag, Device& in, T0&& arg0,
                                                                 T1&& arg1, Ts&&... args) {
    return read(in, std::forward<T0>(arg0)) &&
           read(in, std::forward<T1>(arg1), std::forward<Ts>(args)...);
}

template <class Device, class... Ts>
inline bool read(Device& in, Ts&&... args) {
    static_assert(!std::is_base_of<io_tag, Device>::value, "no matching call for read");
    return read(typename Device::category{}, in, std::forward<Ts>(args)...);
}

}

namespace ac {

template <class Device>
inline int write(Device& out, char arg) {
    out.write_char(arg);
    return 1;
}

namespace detail {

template <class Device, class UInt>
inline char* write_unsigned_int(Device& out, UInt arg, char* last) {
    auto base = out.get_base();
    if (arg == 0) {
        *--last = '0';
    } else if (EXPECT_TRUE(base == 10)) {
        for (; arg; arg /= 10)
            *--last = static_cast<char>('0' + arg % 10);
    } else {
        for (; arg; arg /= base) {
            UInt digit = arg % base;
            *--last = static_cast<char>(digit < 10 ? '0' + digit : 'A' - 10 + digit);
        }
    }
    return last;
}

}

template <class Device, class Int>
inline std::enable_if_t<is_signed_int<Int>::value, int> write(text_io_tag, Device& out, Int arg) {
    char* last = out.get_end();
    auto unsigned_arg = static_cast<std::make_unsigned_t<Int>>(arg);
    if (arg < 0) {
        last = detail::write_unsigned_int(out, ~unsigned_arg + 1, last);
        *--last = '-';
    } else {
        last = detail::write_unsigned_int(out, unsigned_arg, last);
    }
    return out.write_value(last);
}

template <class Device, class T0, class T1, class... Ts>
inline std::enable_if_t<!is_iterator<T0>::value, int> write(io_tag, Device& out, const T0& arg0,
                                                            const T1& arg1, const Ts&... args) {
    int chars_written = write(out, arg0);
    return chars_written + write(out, arg1, args...);
}

template <class Device, class... Ts>
inline int write(Device& out, const Ts&... args) {
    static_assert(!std::is_base_of<io_tag, Device>::value, "no matching call for write");
    return write(typename Device::category{}, out, args...);
}

template <class Device, class... Ts>
inline int writeln(Device& out, const Ts&... args) {
    static_assert(io_traits<Device>::text, "text device expected");
    return write(out, args..., '\n');
}

class buffered_input_device {
public:
    
    buffered_input_device(buffered_input_device const&) = delete;
    buffered_input_device& operator = (buffered_input_device const&) = delete;

    virtual ~buffered_input_device() {}

    inline char read_char() {
        if (EXPECT_FALSE(head_ >= tail_)) fill_buffer();
        return *head_++;
    }

    void put_back() { --head_; }

protected:
    buffered_input_device(const char* head, const char* tail) : head_{head}, tail_{tail} {}

    virtual void fill_buffer() = 0;

    const char* head_;
    const char* tail_;
};

class text_input_device {
public:
    
    uint32_t get_base() const { return base_; }
    
protected:
    uint32_t base_ = 10;
};

class text_buffered_input_device : public text_input_device, public buffered_input_device {
public:
    using category = text_io_tag;

protected:
    text_buffered_input_device(const char* head, const char* tail)
        : buffered_input_device(head, tail) {}
};

template <bool Binary>
using input_device_base_t =
    conditional_t<Binary, buffered_input_device, text_buffered_input_device>;

template <bool Binary, uint32_t BufferSize = 1 << 11>
class input_file final : public input_device_base_t<Binary> {
public:
    input_file(std::FILE* file = stdin, bool line_buffered = true, bool take_ownership = false)
        : input_device_base_t<Binary>(buffer_, buffer_),
          file_{file},
          line_buffered_{line_buffered},
          owner_{take_ownership} {}

    input_file(const char* file_name)
        : input_file(std::fopen(file_name, Binary ? "rb" : "r"), false, true) {}

    ~input_file() override {
        if (owner_) std::fclose(file_);
    }

private:
    void fill_buffer() override {
        this->head_ = buffer_;
        *buffer_ = '\0';
        if (EXPECT_TRUE(!line_buffered_)) {
            this->tail_ = this->head_ + std::fread(buffer_, 1, BufferSize, file_);
        } else {
            this->tail_ = this->head_;
            if (std::fgets(buffer_, BufferSize, file_)) {
                while (*this->tail_) ++this->tail_;
            }
        }
    }

    std::FILE* file_;
    const bool line_buffered_;
    const bool owner_;
    char buffer_[BufferSize];
};

using text_input_file   = input_file<false>;

template <uint32_t BufferSize = 1 << 11>
class buffered_output_device {
public:
    
    buffered_output_device(buffered_output_device const&) = delete;
    buffered_output_device& operator = (buffered_output_device const&) = delete;

    virtual ~buffered_output_device() {}

    inline void write_char(char arg) {
        *tail_++ = arg;
        flush_maybe();
    }

    void flush() {
        flush_buffer(static_cast<int>(tail_ - buffer_));
        tail_ = buffer_;
    }

protected:
    char  buffer_[BufferSize];
    char* tail_;

    buffered_output_device() : tail_{buffer_} {}

    virtual void flush_buffer(int count) = 0;

    inline void flush_maybe() {
        if (EXPECT_FALSE(tail_ == buffer_ + BufferSize)) flush();
    }

    template <class InputIterator>
    int write_string_impl(InputIterator arg, int count) {
        int chars_written = count;
        if (EXPECT_TRUE(tail_ + count < buffer_ + BufferSize)) {
            if (count == 1) *tail_++ = *arg;
            else tail_ = std::copy_n(arg, count, tail_);
        } else {
            int chunk_size = static_cast<int>(buffer_ + BufferSize - tail_);
            for (;; chunk_size = BufferSize) {
                if (chunk_size > count) chunk_size = count;
                tail_ = std::copy_n(arg, chunk_size, tail_);
                flush_maybe();
                if ((count -= chunk_size) == 0) break;
                arg += chunk_size;
            }
        }
        return chars_written;
    }
};

class text_output_device {
public:
    
    explicit text_output_device() { compute_base_power(); }

    uint32_t get_base() const { return base_; }
    
protected:
    void compute_base_power() {
        base_power_ = 1;
        for (uint32_t i = 0; i < precision_; ++i) base_power_ *= base_;
    }

    bool        separate_  = false;
    uint32_t    width_     = 0;
    char        fill_      = ' ';
    uint32_t    base_      = 10;
    uint32_t    precision_ = 9;
    std::string delimiter_ = " ";

    unsigned long long base_power_;
};

template <uint32_t BufferSize = 1 << 11>
class text_buffered_output_device : public text_output_device,
                                    public buffered_output_device<BufferSize> {
public:
    using category = text_io_tag;

    static constexpr uint32_t MaxLength = 1 << 7;

    char* get_end() { return auxiliary_ + MaxLength; }

    inline void write_char(char arg) {
        separate_ = false;
        buffered_output_device<BufferSize>::write_char(arg);
    }

    inline int write_value(const char* begin) {
        int chars_written = separate_ ? write_delimiter() : 0;
        chars_written += write_string(begin, static_cast<size_t>(get_end() - begin));
        separate_ = true;
        return chars_written;
    }

    inline int write_string(const char* arg, size_t length, bool check_width = true) {
        separate_ = false;
        const int count = static_cast<int>(length);
        int chars_written = count;
        if (EXPECT_FALSE(check_width && count < width_)) {
            struct fill_iterator : std::iterator<std::input_iterator_tag, char> {
                fill_iterator(char fill) : fill{fill} {}
                char operator * () const { return fill; }
                void operator ++ () const {}
                void operator += (uint32_t) const {}
                const char fill;
            };
            chars_written += this->write_string_impl(fill_iterator(fill_), width_ - count);
        }
        return chars_written + this->write_string_impl(arg, count);
    }

    inline int write_delimiter() {
        return write_string(delimiter_.c_str(), delimiter_.size(), false);
    }

private:
    char auxiliary_[MaxLength];
};

template <bool Binary, uint32_t BufferSize>
using output_device_base_t = std::conditional_t<Binary, buffered_output_device<BufferSize>,
                                                text_buffered_output_device<BufferSize>>;

template <bool Binary, uint32_t BufferSize = 1 << 11>
class output_file final : public output_device_base_t<Binary, BufferSize> {
public:
    output_file(FILE* file = stdout, bool take_ownership = false)
        : file_{file}, owner_{take_ownership} {}

    output_file(const char* file_name)
        : output_file(std::fopen(file_name, Binary ? "wb" : "w"), true) {}

    ~output_file() override {
        this->flush();
        if (owner_) std::fclose(file_);
    }

private:
    void flush_buffer(int count) override {
        std::fwrite(this->buffer_, 1, count, file_);
        std::fflush(file_);
    }

    std::FILE* file_;
    const bool owner_;
};

using text_output_file   = output_file<false>;

}

using namespace ac;

void solve(text_input_file& in, text_output_file& out);

#pragma GCC target("avx,avx2")

namespace ac {

template <class... Ts>
struct scalar_traits;

/// caide keep
template <class T>
struct scalar_traits<T> {
    /// caide concept
    using type = T;
};

}

namespace ac {

}

class BSolver {
public:
    text_input_file& in;
    text_output_file& out;
    text_output_file err;

    BSolver(text_input_file& in, text_output_file& out) : in(in), out(out), err(stdout) {}

    void solve() {
        ll n, k;
        read(in, n, k);
        ll a = max(1ll, k - n);
        ll b = (k - 1) / 2;
        writeln(out, max(0ll, b - a + 1));
    }
};

void solve(text_input_file& in, text_output_file& out) {
    BSolver solver(in, out);
    solver.solve();
}

int main() {
    const char* input_file_name = "";
    unique_ptr<text_input_file> in;
    if (*input_file_name) {
        in.reset(new text_input_file(input_file_name));
    } else {
        in.reset(new text_input_file(stdin, false));
    };
    const char* output_file_name = "";
    unique_ptr<text_output_file> out;
    if (*output_file_name) {
        out.reset(new text_output_file(output_file_name));
    } else {
        out.reset(new text_output_file(stdout));
    }
    solve(*in, *out);
    return 0;
}