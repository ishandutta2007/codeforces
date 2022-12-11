var w,h,w1,h1:longint;
    s:int64;
begin
 s:=0;
 readln(w,h);
 w1:=2;
 while w1<=w do
 begin
  h1:=2;
  while h1<=h do
  begin
   s:=s+((w-w1+1)*(h-h1+1));
   h1:=h1+2;
  end;
  w1:=w1+2;
 end;
 writeln(s);
end.