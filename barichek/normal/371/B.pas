uses math;
var
  a,a2,a3,a5,b,b2,b3,b5:longint;
  ans:longint;
begin
  read(a,b);
  a2:=0;
  a3:=0;
  a5:=0;
  b2:=0;
  b3:=0;
  b5:=0;
  while a mod 2=0 do
    begin
      inc(a2);
      a:=a div 2;
    end;
  while a mod 3=0 do
    begin
      inc(a3);
      a:=a div 3;
    end;
  while a mod 5=0 do
    begin
      inc(a5);
      a:=a div 5;
    end;
  while b mod 2=0 do
    begin
      inc(b2);
      b:=b div 2;
    end;
  while b mod 3=0 do
    begin
      inc(b3);
      b:=b div 3;
    end;
  while b mod 5=0 do
    begin
      inc(b5);
      b:=b div 5;
    end;
  ans:=abs(a2-b2)+abs(a3-b3)+abs(a5-b5);
  if a<>b then ans:=-1;
  writeln(ans);
end.