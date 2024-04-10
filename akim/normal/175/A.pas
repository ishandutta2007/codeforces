var s,s1,s2,s3:string;
    max,t1,t2,t3,i,f,g,l:longint;
begin
 readln(s);
 l:=length(s);
 if l>21 then begin writeln(-1);halt(0);end;
 max:=-1;
 for i:=1 to l-2 do
 for f:=1 to l-i-1 do
 begin
  g:=l-i-f;
  s1:=copy(s,1,i);
  s2:=copy(s,i+1,f);
  s3:=copy(s,i+f+1,g);
  if (i>7)or(f>7)or(g>7) then continue;
  if (i>1)and(s1[1]='0') then continue;
  if (f>1)and(s2[1]='0') then continue;
  if (g>1)and(s3[1]='0') then continue;
  val(s1,t1);
  val(s2,t2);
  val(s3,t3);
  if (t1>1000000)or(t2>1000000)or(t3>1000000) then continue;
  if max<t1+t2+t3 then begin max:=t1+t2+t3;end;
 end;
 writeln(max);
end.