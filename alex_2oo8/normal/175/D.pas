program problem4;
uses math;

const eps = 0.0001;

type tHpArr = array[0..200] of real;
     tTank = record
               hp: tHpArr;
               dt, l, r, p: longWord;
             end;

procedure shot( var pl1, pl2: tTank );
var i, j: longInt;
    hp: tHpArr;
begin
  for i := 0 to 200 do
    hp[i] := 0.0;

  for i := 0 to 200 do
  begin
    if ( pl2.hp[i] > 0 ) then
    begin
      hp[i] := hp[i] + ( pl2.hp[i] * pl1.p / 100 );
      for j := (i-pl1.r) to (i-pl1.l) do
        hp[ max( 0, j ) ] := hp[ max( 0, j ) ] + ( ( ( pl2.hp[i] * ( 100 - pl1.p ) ) / 100 ) / (pl1.r-pl1.l+1) );
    end;
  end;

  pl2.hp := hp;
end;

var pl1, pl2: tTank;
    i, hp1, hp2, t: longWord;
    ans, x: real;

begin
  readln( hp1, pl1.dt, pl1.l, pl1.r, pl1.p );
  readln( hp2, pl2.dt, pl2.l, pl2.r, pl2.p );

  if ( pl1.p = 100 ) then
  begin
    writeln( 0.0:0:8 );
    halt;
  end;
  if ( pl2.p = 100 ) then
  begin
    writeln( 1.0:0:8 );
    halt;
  end;

  for i := 0 to 200 do
  begin
    pl1.hp[i] := 0.0;
    pl2.hp[i] := 0.0;
  end;
  pl1.hp[hp1] := 1.0;
  pl2.hp[hp2] := 1.0;

  ans := 0.0;
  x := 0.0;
  t := 0;
  while ( (1-pl1.hp[0])*(1-x) > eps ) do
  begin
    if ( t mod pl1.dt ) = 0 then
    begin
      shot( pl1, pl2 );
      ans := ans + ( (1-pl1.hp[0]) * pl2.hp[0] );
      x := x + pl2.hp[0];
      pl2.hp[0] := 0.0;
    end;
    if ( t mod pl2.dt ) = 0 then
      shot( pl2, pl1 );

    inc( t );
  end;

  writeln( ans:0:8 );
end.