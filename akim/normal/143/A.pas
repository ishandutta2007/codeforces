var i1,i2,i3,i4,r1,r2,c1,c2,d1,d2:longint;
begin
 readln(r1,r2,c1,c2,d1,d2);
 for i1:=1 to 9 do
  for i2:=1 to 9 do
   for i3:=1 to 9 do
    for i4:=1 to 9 do
     if (i1<>i2)and(i1<>i3)and(i1<>i4)and
        (i2<>i3)and(i2<>i4)and
        (i3<>i4)and
        (i1+i2=r1)and(i3+i4=r2)and
        (i1+i3=c1)and(i2+i4=c2)and
        (i1+i4=d1)and(i2+i3=d2)then begin writeln(i1,' ',i2);writeln(i3,' ',i4);halt(0);end;
 writeln('-1');
end.