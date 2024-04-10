var n,k,i: longint;
begin
read (n,k);
for i:=0 to k-1 do write (n-i,' ');
for i:=1 to n-k do write (i,' ')
end.