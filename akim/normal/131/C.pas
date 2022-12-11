var s:int64;i,a,b,c,f:longint;
    z:array[-1..33,-1..33]of int64;
begin
 z[0,0]:=1;
 for i:=1 to 32 do
  for f:=0 to 32 do
   if (i<>0)or(f<>0) then z[i,f]:=z[i-1,f]+z[i-1,f-1];
 {for i:=0 to 5 do
 begin
  for f:=0 to 5 do
   write(z[i,f],' ');
  writeln;
 end;}
 readln(a,b,c);
 s:=0;
 for i:=1 to c-4 do
 begin
  if (i<=b)and(c-i<=a) then s:=s+z[b,i]*z[a,c-i];
 end;
 writeln(s);
end.