var x:array[1..1000000]of int64;
    a,b,c,i,f,g:longint;s:int64;
begin
 for i:=1 to 1000000 do
 begin
  f:=i;
  while f<=1000000 do
  begin
   inc(x[f]);
   f:=f+i;
  end;
 end;
 readln(a,b,c);
 for i:=1 to a do
  for f:=1 to b do
   for g:=1 to c do
    s:=(s+x[i*f*g])mod 1073741824;
 writeln(s);
end.