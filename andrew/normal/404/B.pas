var
 s1,s2,s3,r,k,a,d:extended;
 i,n:longint;

begin
 readln(a,d);
 readln(n);

 s1:=a+a;
 s2:=s1+a;
 s3:=s2+a;
 k:=0;
 for i:=1 to n do
 begin
  k:=k+d;
  r:=frac(k/s3)*s3;

  if r<a then writeln(r:0:10,' ',0.0:0:10)
  else if r<s1 then writeln(a:0:10,' ',r-a:0:10)
  else if r<s2 then writeln(a-r+s1:0:10,' ',a:0:10)
  else writeln(0.0:0:10,' ',a-r+s2:0:10)
 end;
end.