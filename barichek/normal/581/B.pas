uses math;
var
  a,b:array[1..1000000]of int64;
  n,maxi:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=n downto 1 do
    begin
      if a[i]>maxi then begin b[i]:=0; maxi:=a[i]; end
      else b[i]:=maxi-a[i]+1;
    end;
  for i:=1 to n do
    write(b[i],' ');
end.