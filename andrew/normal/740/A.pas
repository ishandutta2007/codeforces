var
 min,a,b,c,d,n,k,i,j,l,o,ch1,ch2,sc,ch3:int64;
begin
 readln(n,a,b,c);
 ch1:=n mod 4;
 if ch1=0 then begin writeln(0); halt; end;
 min:=maxlongint;
 ch1:=4-ch1;
 if ch1=1 then
 begin
  if a<min then min:=a;
  if c*3<min then min:=c*3;
  if b+c<min then min:=b+c;
 end;
 if ch1=2 then
 begin
  if b<min then min:=b;
  if 2*a<min then min:=a*2;
  if 2*c<min then min:=2*c;
 end;
 if ch1=3 then
 begin
  if c<min then min:=c;
  if a*3<min then min:=a*3;
  if a+b<min then min:=a+b;
 end;
 writeln(min);
end.