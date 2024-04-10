var
 k2,k3,k5,k6,sum1,sum2:int64;
 sc,i,j,min:longint;
procedure proverka;
begin
 if (k2<=k6)and(k2<=k5)then min:=k2
 else
 if (k5<=k6)and(k2>=k5)then min:=k5
 else
 min:=k6;
end;
begin
 readln(k2,k3,k5,k6);
 proverka;
 sum1:=256*min;
 k2:=k2-min;
 if (k2< k3)then min:=k2 else min:=k3;
 sum1:=sum1+(32*min);
 writeln(sum1);
end.