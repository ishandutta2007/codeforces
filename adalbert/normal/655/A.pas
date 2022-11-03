var    st1,st2,st3,st4:string;
       x:char;
       b,a:array[1..10000] of char;
       s,j, k,i:longint;
begin
readln(st1);
if st1[1]<>'X' then
    begin
    inc(k);
    a[k]:=st1[1];
    end;
if st1[2]<>'X' then
    begin
    inc(k);
    a[k]:=st1[2];
    end;



readln(st2);
    if st2[2]<>'X' then
    begin
    inc(k);
    a[k]:=st2[2];
    end;
if st2[1]<>'X' then
    begin
    inc(k);
    a[k]:=st2[1];
    end;
k:=0;




readln(st3);
if st3[1]<>'X' then
    begin
    inc(k);
    b[k]:=st3[1];
    end;
if st3[2]<>'X' then
    begin
    inc(k);
    b[k]:=st3[2];
    end;
readln(st4);
if st4[2]<>'X' then
    begin
    inc(k);
    b[k]:=st4[2];
    end;
if st4[1]<>'X' then
    begin
    inc(k);
    b[k]:=st4[1];
    end;

for i:=1 to 3 do a[i+3]:=a[i];

for i:=1 to 3 do b[i+3]:=b[i];
for i:=1 to 6 do
if a[1]=b[i] then break;
j:=1;
while (a[j]=b[i]) and (s<3) do
     begin

     inc(s);
     inc(j);
     inc(i);
     end;
if s=3 then write ('YES') else write('NO');
end.