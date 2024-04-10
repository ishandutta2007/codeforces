{$o+,r-,s-,q-,i-}
var abc:array[1..105,'A'..'Z']of boolean;
    a:array[1..105]of longint;
    x,y,i,f:longint;
    s:int64;
    c:char;
begin
 readln(x,y);
 for i:=1 to x do
 begin
  for f:=1 to y do
  begin
   read(c);
   if abc[f,c]=false then begin abc[f,c]:=true;inc(a[f]);end;
  end;
  readln;
 end;
 s:=1;
 for i:=1 to y do
  s:=(s*a[i])mod 1000000007;
 writeln(s);
end.