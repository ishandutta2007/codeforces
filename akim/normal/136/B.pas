var a,b,c,d,e,k:longint;
    s:string;
begin
 s:='';
 readln(b,c);
 while (b<>0)or(c<>0) do
 begin
  d:=b mod 3;
  e:=c mod 3;
  b:=b div 3;
  c:=c div 3;
  k:=0;
  while (d+k) mod 3<>e do
   inc(k);
  case k of
   0:s:=s+'0';
   1:s:=s+'1';
   2:s:=s+'2';
  end;
 end;
 k:=1;a:=0;
 while s<>'' do
 begin
  case s[1]of
  '0':a:=a;
  '1':a:=a+k;
  '2':a:=a+k*2;
  end;
  delete(s,1,1);k:=k*3;
 end;
 writeln(a);
end.