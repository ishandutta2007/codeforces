program gorergo;
var n,a,b,c,h:int64; x:array [1..100000] of int64; i:longint;
begin
read(a,b,c);
readln(n);
for i:=1 to n do
  begin
  read(x[i]);
  if (x[i]<c) and (x[i]>b) then inc(h);
  end;
writeln(h);
end.