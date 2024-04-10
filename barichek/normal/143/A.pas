uses math;
var
  a,b,c,d,r1,r2,c1,c2,d1,d2:longint;
begin
  read(r1,r2,c1,c2,d1,d2);
  if (r1+r2+c1+c2+d1+d2) mod 3<>0 then begin writeln(-1); halt; end;
  c:=(c1-d1+r2) div 2;
  a:=c1-c;
  b:=d2-c;
  d:=r2-c;
  if (a<=0) or (b<=0) or (c<=0) or (d<=0) or (a>9) or (b>9) or (c>9) or (d>9) then begin writeln(-1); halt; end;
  if (a=b) or (a=c) or (a=d) or (b=c) or (b=d) or (c=d) then begin writeln(-1); halt; end;
  writeln(a,' ',b);
  writeln(c,' ',d);
end.