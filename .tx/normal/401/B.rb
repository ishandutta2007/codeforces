def rsm(&block)
   readline.split.map{|i| block.yield(i)}
end

def rsmi
   rsm {|i| i.to_i}
end

x, k = rsmi
a = Array.new(x - 1, 0)
k.times {
   r = rsmi
   t, x = r[0], r[1]
   a[x - 1] = 2
   if t == 1
      y = r[2]
      a[y - 1] = 1
   end

}

s1 = a.count {|i| i == 0}
s2 = 0
a.length.times { |i|
   if a[i] == 0
      s2 += 1
      a[i] = 2
      if i + 1 < a.length
         a[i + 1] = 1 if a[i + 1] == 0
      end
   end
}
printf("%d %d", s2, s1)