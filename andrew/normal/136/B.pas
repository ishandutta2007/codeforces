var
 ch1,ch2,ch3,a,b,c,k,i,j,sc:Longint;
 s1,s2,s3:ansistring;
begin
 readln(a,b);
 s1:='';
 while a<>0 do
 begin
  s1:=chr(a mod 3 +48)+s1;
  a:=a div 3;
 end;


 s2:='';
 while b<>0 do
 begin
  s2:=chr(b mod 3 +48)+s2;
  b:=b div 3;
 end;
 while length(s1)<>length(s2) do if length(s1)<length(s2) then s1:='0'+s1 else s2:='0'+s2;
 s3:=s1;
 for i:=1 to length(s1) do
 begin
  ch1:=ord(s1[i])-48;
  ch2:=ord(s2[i])-48;
  if ch1>ch2 then ch2:=3+ch2;
  ch3:=ch2-ch1;
  s3[i]:=chr(ch3+48);
 end;
 sc:=0;
 c:=0;
 for i:=1 to length(s3) do
 begin
  c:=c*3 + ord(s3[i])-48;
 end;
 writeln(c);
end.