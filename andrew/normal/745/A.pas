var
 a,b:array[1..1000]of longint;
 d,ch1,ch2,i,j,n,m,sc,l,k:longint;
 s:ansistring;
 s1:array[0..100]of ansistring;
begin
 readln(s);
 s1[0]:=s;
 for i:=1 to length(s) do
 begin
  s1[i]:=s1[i-1]+s1[i-1,1];
  delete(s1[i],1,1);

  for j:=1 to i-1 do if s1[i]=s1[j] then begin writeln(i-1); halt; end;
 end;
 writeln(length(s));
end.