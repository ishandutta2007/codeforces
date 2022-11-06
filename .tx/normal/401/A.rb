n, x = readline.split().map {|i| i.to_i}
s = 0
readline.split().map {|i| s += i.to_i}
puts (s.abs + x - 1) / x